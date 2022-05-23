/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_node.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 03:24:59 by seyu              #+#    #+#             */
/*   Updated: 2021/07/09 17:10:45 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_NODE_HPP
# define SET_NODE_HPP

# include <memory>

# include "functional.hpp"
# include "utility.hpp"

namespace	ft
{

template <	typename T,
			typename Compare,
			typename Allocator = std::allocator<T> >
class	set_node
{
public:
	typedef T							value_type;
	typedef std::size_t					size_type;
	typedef std::ptrdiff_t				difference_type;
	typedef	Compare						compare_type;
	typedef Allocator					allocator_type;
	typedef value_type&					reference;
	typedef typename Allocator::pointer	pointer;

	enum	Color { RED, BLACK, DOUBLE_BLACK };

	// nil-node constructure
	set_node()
		: value(NULL), _color(BLACK), _allocValue(allocator_type()), _allocNode(std::allocator<set_node>())
	{
		_parent = this;
		_left = this;
		_right = this;
	}

	// normal node constructure
	set_node(const value_type& val, set_node* const nil, const allocator_type& alloc = allocator_type())
		: _color(RED), _parent(nil), _left(nil), _right(nil), _allocValue(alloc), _allocNode(std::allocator<set_node>())
	{
		value = _allocValue.allocate(1);
		_allocValue.construct(value, val);
	}

	set_node(const set_node& other)
		: _color(other._color), _allocValue(other._allocValue), _allocNode(other._allocNode)
	{
		if (other.value == NULL)
		{
			value = NULL;
			_parent = this;
			_left = this;
			_right = this;
		}
		else
		{
			value = _allocValue.allocate(1);
			_allocValue.construct(value, *(other.value));
			_parent = other._parent;
			_left = other._left;
			_right = other._right;
		}
	}

	~set_node()
	{
		if (value == NULL)
			return ;
		_allocValue.destroy(value);
		_allocValue.deallocate(value, 1);
	}

	set_node&	operator=(const set_node& other)
	{
		if (this != &other)
		{
			_color = other._color;
			if (value != NULL)
				_allocValue.destroy(value);
			if (other.value == NULL)
				value = NULL;
			else
				_allocValue.construct(value, *(other.value));
			_parent = other._parent;
			_left = other._left;
			_right = other._right;
			_allocValue = other._allocValue;
			_allocNode = other._allocNode;
		}
		return (*this);
	}

	set_node*	next()
	{
		set_node*	itr = this;

		if (itr->_right->_is_nil())
		{
			while (itr->_parent->_is_nil() == false
					&& itr->_parent->_right == itr)
				itr = itr->_parent;
			return (itr->_parent);
		}
		else
		{
			itr = itr->_right;
			while (itr->_left->_is_nil() == false)
				itr = itr->_left;
			return (itr);
		}
	}

	set_node*	prev()
	{
		set_node*	itr = this;

		if (itr->_left->_is_nil())
		{
			while (itr->_parent->_is_nil() == false
					&& itr->_parent->_left == itr)
				itr = itr->_parent;
			return (itr->_parent);
		}
		else
		{
			itr = itr->_left;
			while (itr->_right->_is_nil() == false)
				itr = itr->_right;
			return (itr);
		}
	}

	set_node*	find(const T& target)
	{
		compare_type	comp = compare_type();

		if (this->_is_nil())
		{
			if (this == _parent)
				return (this);
			return (_parent->find(target));
		}
		else
		{
			set_node*	itr = this;

			while (itr->_is_nil() == false)
			{
				if (*(itr->value) == target)
					return (itr);
				else if (comp(target, *(itr->value)))
					itr = itr->_left;
				else
					itr = itr->_right;
			}
			return (itr);
		}
	}

	set_node*	insert(const value_type& val, set_node* nil)
	{
		if (this == nil && _parent != nil)
			return (_parent->insert(val, nil));

		set_node*	new_node;

		new_node = _allocNode.allocate(1);
		_allocNode.construct(new_node, set_node(val, nil));

		if (this == nil)
		{
			_parent = new_node;
			_left = new_node;
			_right = new_node;
			return (new_node);
		}

		set_node*		itr;
		compare_type	comp = compare_type();

		itr = this;
		while (true)
		{
			if (val == *(itr->value))
			{
				_allocNode.destroy(new_node);
				_allocNode.deallocate(new_node, 1);
				return (NULL);
			}
			else if (comp(val, *(itr->value)))
			{
				if (itr->_left->_is_nil() == true)
				{
					itr->_connect(new_node, NULL);
					break ;
				}
				else
					itr = itr->_left;
			}
			else
			{
				if (itr->_right->_is_nil() == true)
				{
					itr->_connect(NULL, new_node);
					break ;
				}
				else
					itr = itr->_right;
			}
		}

		if (new_node->_parent->_color == RED)
			new_node->insert_fixup();
		return (new_node);
	}

	// this			: RED set_node
	// this->parent	: unknown
	void	insert_fixup()
	{
		// if) this == root OR this->parent is BLACK set_node
		if (this->_is_root() || _parent->_color == BLACK)
			return ;
		// this			: RED set_node, have parent node
		// this->parent	: RED set_node

		// if) this->parent == root
		if (_parent->_is_root())
		{
			_parent->_color = BLACK;
			return ;
		}
		// this			: RED set_node, have parent node
		// this->parent	: RED set_node, have parent node

		set_node*	p_sibling = _parent->_sibling();

		// if) this->parent->sibling == BLACK or NIL
		if (p_sibling->_color == BLACK) // restructing
		{
			compare_type	comp = compare_type();

			bool	this_less_than_parent = comp(*(value), *(_parent->value));
			bool	parent_less_than_gparent = comp(*(_parent->value), *(_parent->_parent->value));

			// if)   this < parent < grandparent OR grandparent < parent < this
			// then) rotate parent
			//     B        B    ││  B            B
			//   ┌─┴      ┌─┴─┐  ││  ┴─┐        ┌─┴─┐
			//   R    to  R   R  OR    R    to  R   R
			// ┌─┴               ││    ┴─┐
			// R                 ││      R
			if ((this_less_than_parent && parent_less_than_gparent)
					|| (!this_less_than_parent && !parent_less_than_gparent))
			{
				_parent->_rotate();
				_parent->_color = BLACK;
				this->_color = RED;
				_sibling()->_color = RED;
			}
			// if)   parent < this < grandparent OR grandparent < this < parent
			// then) rotate this twice
			//     B          B        B    ││  B        B            B
			//   ┌─┴        ┌─┴      ┌─┴─┐  ││  ┴─┐      ┴─┐        ┌─┴─┐
			//   R    to    R    to  R   R  OR    R  to    R    to  R   R
			//   ┴─┐      ┌─┴               ││  ┌─┴        ┴─┐
			//     R      R                 ││  R            R
			else
			{
				_rotate();
				_rotate();
				_color = BLACK;
				_left->_color = RED;
				_right->_color = RED;
			}
		}
		// if) this->parent->sibling == RED
		// then) paint parent and parent's sibling in BLACK
		//       AND paint grandparent in RED
		//       AND recursion with grandparent
		//     B            R
		//   ┌─┴─┐        ┌─┴─┐
		//   R   R  to    B   B
		// ┌─┴          ┌─┴
		// R            R
		else
		{
			p_sibling->_color = BLACK;
			_parent->_color = BLACK;
			_parent->_parent->_color = RED;
			_parent->_parent->insert_fixup();
		}
	}

	void	erase()
	{
		// if) this is nil node
		// then) do not erase
		if (this->_is_nil())
			return ;
		// if) this is one node tree
		// then) null tree setting
		if (this->_parent == this->_left && this->_parent == this->_right)
		{
			this->_parent->_parent = this->_parent;
			this->_left->_left = this->_left;
			this->_right->_right = this->_right;
			_allocNode.destroy(this);
			_allocNode.deallocate(this, 1);
			return ;
		}

		if (this->_is_lowest())
			_left->_right = next();
		if (this->_is_highest())
			_right->_left = prev();

		set_node*	successor;

		if (_left->_is_nil() && _right->_is_nil())
			successor = this;
		else if (_left->_is_nil())
			successor = this->next();
		else if (_right->_is_nil())
			successor = this->prev();
		else
		{
			set_node*	prev_node = this->prev();
			set_node*	next_node = this->next();

			if (prev_node->_depth() <= next_node->_depth())
				successor = next_node;
			else
				successor = prev_node;
		}

		if (successor->_color == BLACK)
		{
			successor->_increase_black();
			successor->erase_fixup();
		}

		// successor		: has parent node, has one or no child
		// successor_child	: left, right, or nil node

		set_node*	successor_child;

		if (successor->_left->_is_nil() == false)
			successor_child = successor->_left;
		else
			successor_child = successor->_right;

		if (successor == successor->_parent->_left)
			successor->_parent->_connect(successor_child, NULL);
		else
			successor->_parent->_connect(NULL, successor_child);

		if (this != successor)
		{
			if (this->_is_root())
			{
				successor->_parent = this->_parent;
				this->_parent->_parent = successor;
			}
			else if (this == this->_parent->_left)
				this->_parent->_connect(successor, NULL);
			else
				this->_parent->_connect(NULL, successor);

			successor->_connect(_left, _right);
			successor->_color = _color;
		}

		_allocNode.destroy(this);
		_allocNode.deallocate(this, 1);
	}

	// this -> DOUBLE BLACK set_node
	void	erase_fixup()
	{
		if (this->_is_root())
		{
			_decrease_black();
			return ;
		}

		set_node*	my_sibling = _sibling();

		if (my_sibling->_color == RED)
		{
			_parent->_color = RED;
			my_sibling->_color = BLACK;
			my_sibling->_rotate();
			erase_fixup();
		}
		else if (my_sibling->_right->_color == RED)
		{
			my_sibling->_color = _parent->_color;
			_parent->_color = BLACK;
			my_sibling->_right->_color = BLACK;
			my_sibling->_rotate();
			_decrease_black();
		}
		else if (my_sibling->_left->_color == RED)
		{
			my_sibling->_color = RED;
			my_sibling->_left->_color = BLACK;
			my_sibling->_left->_rotate();
			erase_fixup();
		}
		else // Sibling's children are all black
		{
			_decrease_black();
			my_sibling->_decrease_black();
			_parent->_increase_black();
			_parent->erase_fixup();
		}
	}

	void	clear()
	{
		if (_is_nil())
		{
			if (_parent == this)
				return ;
			_parent->clear();
			_allocNode.destroy(_parent);
			_allocNode.deallocate(_parent, 1);
			_parent = this;
			_left = this;
			_right = this;
			return ;
		}

		if (_left->_is_nil() == false)
		{
			_left->clear();
			_allocNode.destroy(_left);
			_allocNode.deallocate(_left, 1);
		}
		if (_right->_is_nil() == false)
		{
			_right->clear();
			_allocNode.destroy(_right);
			_allocNode.deallocate(_right, 1);
		}
	}

	value_type*		value;

private:

	size_type
			_depth()
	{
		size_type	depth = 0;

		for (set_node* itr = this; itr->_parent->_is_nil() == false; itr = itr->_parent, depth++) ;
		return (depth);
	}

	void	_increase_black()
	{
		if (_color == RED)
			_color = BLACK;
		else if (_color == BLACK)
			_color = DOUBLE_BLACK;
	}

	void	_decrease_black()
	{
		if (_color == BLACK)
			_color = RED;
		else if (_color == DOUBLE_BLACK)
			_color = BLACK;
	}

	bool	_is_nil()
	{
		return (value == NULL);
	}

	bool	_is_root()
	{
		return (_is_nil() == false && _parent->_parent == this);
	}

	bool	_is_lowest()
	{
		return (_is_nil() == false && _left->_right == this);
	}

	bool	_is_highest()
	{
		return (_is_nil() == false && _right->_left == this);
	}

	void	_connect(set_node *left, set_node *right)
	{
		if (left != NULL)
		{
			// if) left is not nil node
			if (left->_is_nil() == false)
			{
				// if) left is root
				// then) root = this
				if (left->_is_root() == true)
					left->_parent->_parent = this;
				// if) this is lowest
				// then) lowest = left
				if (this->_is_lowest() == true)
					this->_left->_right = left;
				left->_parent = this;
			}
			this->_left = left;
		}
		if (right != NULL)
		{
			// if) right is not nil node
			if (right->_is_nil() == false)
			{
				// if) right is root
				// then) root = this
				if (right->_is_root() == true)
					right->_parent->_parent = this;
				// if) this is highest
				// then) highest = right
				if (this->_is_highest() == true)
					this->_right->_left = right;
				right->_parent = this;
			}
			this->_right = right;
		}
	}

	void	_rotate()
	{
		// caution) fix 6 connections without collisions

		set_node*	gparent = _parent->_parent;

		// if) this is parent's left child
		// then) Right-Rotate:
		// G(grand-parent) P(parent) M(me) S(sibling) L(left) R(right)
		//      P           "M"
		//    ┌─┴─┐        ┌─┴─┐
		//   "M"  S  to    L   P
		//  ┌─┴─┐            ┌─┴─┐
		//  L   R            R   S
		if (this == _parent->_left)
		{
			_parent->_connect(_right, NULL); // P to R, R to P
			_connect(NULL, _parent); // M to P, P to M
		}
		// if) this is parent's right child
		// then) Left-Rotate:
		// P(parent), M(me), S(sibling), L(left), R(right)
		//      P           "M"
		//    ┌─┴─┐        ┌─┴─┐
		//    S  "M"  to   P   R
		//      ┌─┴─┐    ┌─┴─┐
		//      L   R    S   L
		else if (this == _parent->_right)
		{
			_parent->_connect(NULL, _left); // P to L, L to P
			_connect(_parent, NULL); // M to P, P to M
		}
		if (gparent->_is_nil() == false)
		{
			if (gparent->_left == _parent)
				gparent->_left = this;
			else if (gparent->_right == _parent)
				gparent->_right = this;
		}
		_parent = gparent; // M to G
	}

	set_node*	_sibling()
	{
		if (this == _parent->_parent)
			return (NULL);
		else if (this == _parent->_left)
			return (_parent->_right);
		else
			return (_parent->_left);
	}

	Color			_color;
	set_node*		_parent;
	set_node*		_left;
	set_node*		_right;

	allocator_type				_allocValue;
	std::allocator<set_node>	_allocNode;
};

}

#endif
