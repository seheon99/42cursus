/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 15:19:55 by seyu              #+#    #+#             */
/*   Updated: 2021/07/09 17:15:31 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP

# include <memory>
# include <cstddef>

# include "algorithm.hpp"
# include "functional.hpp"
# include "utility.hpp"

# include "set_iterator.hpp"
# include "set_node.hpp"

namespace	ft
{

template <	typename Key,
			typename Compare = less<Key>,
			typename Allocator = std::allocator<Key> >
class	set
{
public:
	/* ---------------------------------------- */
	/*               Member Types               */
	/* ---------------------------------------- */

	typedef Key										key_type;
	typedef Key 									value_type;
	typedef std::size_t								size_type;
	typedef std::ptrdiff_t							difference_type;
	typedef Compare									key_compare;
	typedef Compare									value_compare;
	typedef Allocator								allocator_type;
	typedef value_type&								reference;
	typedef const value_type&						const_reference;
	typedef typename Allocator::pointer				pointer;
	typedef typename Allocator::const_pointer		const_pointer;

	typedef set_iterator<set_node<value_type, value_compare, allocator_type>, false>
													iterator;
	typedef set_iterator<set_node<value_type, value_compare, allocator_type>, true>
													const_iterator;
	typedef ft::reverse_iterator<iterator>			reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

	/* ---------------------------------------- */
	/*             Member Function              */
	/* ---------------------------------------- */

	/* constructor */
	set() :	_size(0),
			_allocValue(allocator_type()),
			_allocNode(std::allocator<set_node<value_type, value_compare, allocator_type> >()),
			_compKey(key_compare())
	{
		_alloc_nil();
	}

	explicit set(const Compare& comp, const Allocator& alloc = Allocator())
		: _size(0),
		  _allocValue(alloc),
		  _allocNode(std::allocator<set_node<value_type, value_compare, allocator_type> >()),
		  _compKey(comp)
	{
		_alloc_nil();
	}

	template <	typename InputIt >
	set( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator(),
			typename ft::enable_if<!is_integral<InputIt>::value>::type = 0 )
		: _size(0),
		  _allocValue(alloc),
		  _allocNode(std::allocator<set_node<value_type, value_compare, allocator_type> >()),
		  _compKey(comp)
	{
		_alloc_nil();
		insert(first, last);
	}

	set(const set& other)
		: _size(0),
		  _allocValue(other._allocValue),
		  _allocNode(other._allocNode),
		  _compKey(other._compKey)
	{
		_alloc_nil();
		insert(other.begin(), other.end());
	}

	/* destructor */
	~set()
	{
		_nil->clear();
		_allocNode.destroy(_nil);
		_allocNode.deallocate(_nil, 1);
	}

	/* operator= */
	set&	operator=(const set& other)
	{
		set	other_copy = other;

		swap(other_copy);
		return (*this);
	}

	/* get_allocator */
	allocator_type	get_allocator() const { return _allocValue; }

	/* ---------------------------------------- */
	/*                 Iterator                 */
	/* ---------------------------------------- */

	iterator				begin()			{ return iterator(_nil->next()); }
	const_iterator			begin() const	{ return const_iterator(_nil->next()); }
	iterator				end()			{ return iterator(_nil); }
	const_iterator			end() const		{ return const_iterator(_nil); }
	reverse_iterator		rbegin()		{ return reverse_iterator(iterator(_nil->prev())); }
	const_reverse_iterator	rbegin() const	{ return const_reverse_iterator(iterator(_nil->prev()));}
	reverse_iterator		rend()			{ return reverse_iterator(iterator(_nil)); }
	const_reverse_iterator	rend() const	{ return const_reverse_iterator(iterator(_nil)); }

	/* ---------------------------------------- */
	/*                 Capacity                 */
	/* ---------------------------------------- */

	bool		empty() const		{ return (_size == 0); }
	size_type	size() const		{ return (_size); }
	size_type	max_size() const	{ return (_allocNode.max_size()); }

	/* ---------------------------------------- */
	/*                Modifiers                 */
	/* ---------------------------------------- */

	/* clear */
	void		clear()
	{
		_nil->clear();
		_size = 0;
	}

	/* insert */
	pair<iterator, bool>
				insert(const value_type& value)
	{
		iterator	idx;

		if ((idx = find(value)) != end())
			return (ft::make_pair(idx, false));
		++_size;
		return (ft::make_pair(_nil->insert(value, _nil), true));
	}

	iterator	insert(iterator hint, const value_type& value)
	{
		iterator	idx;

		(void)hint;

		if ((idx = find(value)) != end())
			return (idx);
		idx = iterator(_nil->insert(value, _nil));
		if (idx.get_node() == NULL)
			return (end());
		_size++;
		return (idx);
	}

	template <	typename InputIt >
	void		insert(InputIt first, InputIt last)
	{
		for (InputIt itr = first; itr != last; itr++, _size++)
			_nil->insert(*itr, _nil);
	}

	/* erase */
	void		erase(iterator pos)
	{
		pos.get_node()->erase();
		_size--;
	}

	void		erase(iterator first, iterator last)
	{
		for (iterator itr = first; itr != last; _size--)
			itr++.get_node()->erase();
	}

	size_type	erase(const key_type& key)
	{
		iterator	idx;

		if ((idx = find(key)) == end())
			return (0);
		idx.get_node()->erase();
		_size--;
		return (1);
	}

	/* swap */
	void		swap(set& other)
	{
		ft::swap(_nil, other._nil);
		ft::swap(_size, other._size);
		ft::swap(_allocValue, other._allocValue);
		ft::swap(_allocNode, other._allocNode);
	}

	/* ---------------------------------------- */
	/*                  Loopup                  */
	/* ---------------------------------------- */

	size_type		count(const Key& key) const
	{
		if (find(key) == end())
			return (0);
		return (1);
	}

	iterator		find(const Key& key)
	{
		return iterator(_nil->find(key));
	}
	const_iterator	find(const Key& key) const
	{
		return const_iterator(_nil->find(key));
	}

	pair<iterator, iterator>
					equal_range(const Key& key)
	{
		set_node<value_type, value_compare, allocator_type>*	target_node;

		if ((target_node = _nil->find(key)) == _nil)
			return (ft::make_pair(end(), end()));
		return (ft::make_pair(iterator(target_node), iterator(target_node->next())));
	}

	pair<const_iterator, const_iterator>
					equal_range(const Key& key) const
	{
		set_node<value_type, value_compare, allocator_type>*	target_node;

		if ((target_node = _nil->find(key)) == _nil)
			return (ft::make_pair(end(), end()));
		return (ft::make_pair(const_iterator(target_node), const_iterator(target_node->next())));
	}

	iterator		lower_bound(const Key& key)
	{
		for (iterator itr = begin(); itr != end(); itr++)
		{
			if (*itr >= key)
				return (itr);
		}
		return (end());
	}

	const_iterator	lower_bound(const Key& key) const
	{
		for (const_iterator itr = begin(); itr != end(); itr++)
		{
			if (*itr >= key)
				return (itr);
		}
		return (end());
	}

	iterator		upper_bound(const Key& key)
	{
		for (iterator itr = begin(); itr != end(); itr++)
		{
			if (*itr > key)
				return (itr);
		}
		return (end());
	}

	const_iterator	upper_bound(const Key& key) const
	{
		for (const_iterator itr = begin(); itr != end(); itr++)
		{
			if (*itr > key)
				return (itr);
		}
		return (end());
	}

	/* ---------------------------------------- */
	/*                Observers                 */
	/* ---------------------------------------- */

	key_compare		key_comp() const	{ return _compKey; }
	value_compare	value_comp() const	{ return value_compare(); }

	/* ---------------------------------------- */
	/*           Non-member Functions           */
	/* ---------------------------------------- */

	friend bool		operator==(const set& lhs, const set& rhs)
	{
		if (lhs._size != rhs._size)
			return false;

		set::const_iterator	lhs_itr;
		set::const_iterator	rhs_itr;

		for (lhs_itr = lhs.begin(), rhs_itr = rhs.begin(); lhs_itr != lhs.end(); lhs_itr++, rhs_itr++)
		{
			if (*lhs_itr != *rhs_itr)
				return false;
		}
		return true;
	}

	friend bool		operator!=(const set& lhs, const set& rhs)
	{
		return !(lhs == rhs);
	}

	friend bool		operator< (const set& lhs, const set& rhs)
	{
		return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	friend bool		operator<=(const set& lhs, const set& rhs)
	{
		return !(rhs < lhs);
	}

	friend bool		operator> (const set& lhs, const set& rhs)
	{
		return rhs < lhs;
	}

	friend bool		operator>=(const set& lhs, const set& rhs)
	{
		return !(lhs < rhs);
	}

	friend void		swap(set& lhs, set& rhs)
	{
		lhs.swap(rhs);
	}

private:
	typedef set_node<value_type, value_compare, allocator_type> node_type;

	void	_alloc_nil()
	{
		_nil = _allocNode.allocate(1);
		_allocNode.construct(_nil, node_type());
	}

	// nil's relationship)
	//
	// nil->parent = root
	// nil->left = highest
	// nil->right = lowest
	//
	//       root
	//        │
	//       nil
	//    ┌───┴───┐
	// highest  lowest
	//
	// <CAUTION>
	// if) node->parent->parent == node
	// then) node is root
	// but) nil->parent->parent is always nil
	//
	// if) node->left->right == node
	// then) node is lowest
	// but) nil->left->right is always nil
	//
	// if) node->right->left == node
	// then) node is highest
	// but) nil->right->lest is always nil
	//
	// so) you need to check node->value is NULL or not
	//     before checking node is root, lowest, or highest

	node_type*	_nil;
	size_type	_size;

	allocator_type				_allocValue;
	std::allocator<node_type>	_allocNode;

	key_compare	_compKey;

};

}

#endif
