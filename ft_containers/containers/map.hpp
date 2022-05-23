/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 03:15:50 by seyu              #+#    #+#             */
/*   Updated: 2021/07/09 16:38:51 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <cstddef>

# include "algorithm.hpp"
# include "functional.hpp"
# include "utility.hpp"

# include "map_iterator.hpp"
# include "map_node.hpp"

namespace	ft
{

template <	typename Key,
			typename T,
			typename Compare = ft::less<Key>,
			typename Allocator = std::allocator<ft::pair<const Key, T> > >
class	map
{
public:
	class	value_compare;

	/* ---------------------------------------- */
	/*               Member Types               */
	/* ---------------------------------------- */

	typedef	Key									key_type;
	typedef T									mapped_type;
	typedef ft::pair<const Key, T>				value_type;
	typedef std::size_t							size_type;
	typedef std::ptrdiff_t						difference_type;
	typedef Compare								key_compare;
	typedef Allocator							allocator_type;
	typedef value_type&							reference;
	typedef const value_type&					const_reference;
	typedef typename Allocator::pointer			pointer;
	typedef typename Allocator::const_pointer	const_pointer;

	typedef map_iterator<map_node<value_type, value_compare, allocator_type>, false>
												iterator;
	typedef map_iterator<map_node<value_type, value_compare, allocator_type>, true>
												const_iterator;
	typedef reverse_iterator<const_iterator>	const_reverse_iterator;
	typedef reverse_iterator<iterator>			reverse_iterator;

	/* ---------------------------------------- */
	/*              Member Classes              */
	/* ---------------------------------------- */

	class	value_compare : binary_function<value_type, value_type, bool>
	{
	public:
		value_compare() : comp(Compare()) {}
		value_compare(const value_compare& other) : comp(other.comp) {}
		~value_compare() {}

		value_compare&	operator=(const value_compare& other)
		{
			comp = other.comp;
		}

		bool	operator() (const value_type& lhs, const value_type& rhs) const
		{
			return (comp(lhs.first, rhs.first));
		}
	protected:
		value_compare(Compare c) : comp(c) {}

		Compare comp;
	private:
	};

	/* ---------------------------------------- */
	/*             Member Functions             */
	/* ---------------------------------------- */

	/* constructor */
	map() :	_size(0),
			_allocValue(allocator_type()),
			_allocNode(std::allocator<map_node<value_type, value_compare, allocator_type> >()),
			_compKey(key_compare())
	{
		_alloc_nil();
	}

	explicit map(const Compare& comp, const Allocator& alloc = Allocator())
		: _size(0),
		  _allocValue(alloc),
		  _allocNode(std::allocator<map_node<value_type, value_compare, allocator_type> >()),
		  _compKey(comp)
	{
		_alloc_nil();
	}

	template <	typename InputIt >
	map(InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator(),
			typename ft::enable_if<!is_integral<InputIt>::value>::type = 0)
		: _size(0),
		  _allocValue(alloc),
		  _allocNode(std::allocator<map_node<value_type, value_compare, allocator_type> >()),
		  _compKey(comp)
	{
		_alloc_nil();
		insert(first, last);
	}

	map(const map& other)
		: _size(0),
		  _allocValue(other._allocValue),
		  _allocNode(other._allocNode),
		  _compKey(other._compKey)
	{
		_alloc_nil();
		insert(other.begin(), other.end());
	}

	/* destructor */
	~map()
	{
		_nil->clear();
		_allocNode.destroy(_nil);
		_allocNode.deallocate(_nil, 1);
	}

	/* operator= */
	map&		operator=(const map& other)
	{
		map	other_copy = other;

		swap(other_copy);
		return (*this);
	}

	/* get_allocator */
	allocator_type
				get_allocator() const { return _allocValue; }

	/* ---------------------------------------- */
	/*              Element Access              */
	/* ---------------------------------------- */

	/* at */
	T&			at(const Key& key)
	{
		iterator	idx = find(key);

		if (idx == end())
			throw std::out_of_range("map");
		return (idx->second);
	}

	const T&	at(const Key& key) const
	{
		iterator	idx = find(key);

		if (idx == end())
			throw std::out_of_range("map");
		return (idx->second);
	}

	/* operator[] */
	T&			operator[](const Key& key)
	{
		iterator	idx = find(key);

		if (idx == end())
			idx = insert(end(), make_pair(key, T()));
		return (idx->second);
	}

	/* ---------------------------------------- */
	/*                Iterators                 */
	/* ---------------------------------------- */

	/* begin */
	iterator	begin()			{ return iterator(_nil->next()); }
	const_iterator
				begin() const	{ return const_iterator(_nil->next()); }

	/* end */
	iterator	end()			{ return iterator(_nil); }
	const_iterator
				end() const		{ return const_iterator(_nil); }

	/* rbegin */
	reverse_iterator
				rbegin()		{ return reverse_iterator(iterator(_nil->prev())); }
	const_reverse_iterator
				rbegin() const	{ return const_reverse_iterator(iterator(_nil->prev())); }

	/* rend */
	reverse_iterator
				rend()			{ return reverse_iterator(iterator(_nil)); }
	const_reverse_iterator
				rend() const	{ return const_reverse_iterator(iterator(_nil)); }

	/* ---------------------------------------- */
	/*                 Capacity                 */
	/* ---------------------------------------- */

	/* empty */
	bool		empty() const	{ return (_size == 0); }

	/* size */
	size_type	size() const	{ return (_size); }

	/* max_size */
	size_type	max_size() const{ return (_allocNode.max_size()); }

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

		if ((idx = find(value.first)) != end())
			return (ft::make_pair(idx, false));
		++_size;
		return (ft::make_pair(_nil->insert(value, _nil), true));
	}

	iterator	insert(iterator hint, const value_type& value)
	{
		map_node<value_type, value_compare, allocator_type>*	new_node;

		iterator	idx;

		(void)hint;

		if ((idx = find(value.first)) != end())
			return (idx);
		new_node = _nil->insert(value, _nil);
		if (new_node == NULL)
			return (end());
		_size++;
		return (iterator(new_node));
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
		{
			map_node<value_type, value_compare, allocator_type>*	target_node;

			target_node = itr++.get_node();
			target_node->erase();
		}
	}

	size_type	erase(const key_type& key)
	{
		iterator	idx;

		idx = find(key);
		if (idx == end())
			return (0);
		idx.get_node()->erase();
		_size--;
		return (1);
	}

	/* swap */
	void		swap(map& other)
	{
		ft::swap(_nil, other._nil);
		ft::swap(_size, other._size);
		ft::swap(_allocValue, other._allocValue);
		ft::swap(_allocNode, other._allocNode);
	}

	/* ---------------------------------------- */
	/*                  Loopup                  */
	/* ---------------------------------------- */

	/* count */
	size_type	count(const Key& key) const
	{
		if (find(key) == end())
			return (0);
		return (1);
	}

	/* find */
	iterator	find(const Key& key)
	{
		return (iterator(_nil->find(make_pair(key, T()))));
	}

	const_iterator
				find(const Key& key) const
	{
		return (const_iterator(_nil->find(make_pair(key, T()))));
	}

	/* equal_range */
	pair<iterator, iterator>
				equal_range(const Key& key)
	{
		map_node<value_type, value_compare, allocator_type>*	target_node;

		target_node = _nil->find(make_pair(key, T()));
		if (target_node == _nil)
			return (ft::make_pair(end(), end()));
		return (ft::make_pair(iterator(target_node), iterator(target_node->next())));
	}

	pair<const_iterator, const_iterator>
				equal_range(const Key& key) const
	{
		map_node<value_type, value_compare, allocator_type>*	target_node;

		target_node = _nil->find(make_pair(key, T()));
		if (target_node == _nil)
			return (ft::make_pair(end(), end()));
		return (ft::make_pair(const_iterator(target_node), const_iterator(target_node->next())));
	}

	/* lower_bound */
	iterator	lower_bound(const Key& key)
	{
		for (iterator itr = begin(); itr != end(); itr++)
		{
			if (itr->first >= key)
				return (itr);
		}
		return (end());
	}

	const_iterator
				lower_bound(const Key& key) const
	{
		for (const_iterator itr = begin(); itr != end(); itr++)
		{
			if (itr->first >= key)
				return (itr);
		}
		return (end());
	}

	/* upper_bound */
	iterator	upper_bound(const Key& key)
	{
		for (iterator itr = begin(); itr != end(); itr++)
		{
			if (itr->first > key)
				return (itr);
		}
		return (end());
	}

	const_iterator
				upper_bound(const Key& key) const
	{
		for (const_iterator itr = begin(); itr != end(); itr++)
		{
			if (itr->first > key)
				return (itr);
		}
		return (end());
	}

	/* ---------------------------------------- */
	/*                Observers                 */
	/* ---------------------------------------- */

	/* key_comp */
	key_compare	key_comp() const	{ return _compKey; }

	/* value_comp */
	value_compare
				value_comp() const	{ return value_compare(); }

	/* ---------------------------------------- */
	/*           Non-member Functions           */
	/* ---------------------------------------- */

	/* operator== */
	friend bool	operator==(const map& lhs, const map& rhs)
	{
		if (lhs._size != rhs._size)
			return false;

		map::const_iterator	lhs_itr;
		map::const_iterator	rhs_itr;

		for (lhs_itr = lhs.begin(), rhs_itr = rhs.begin(); lhs_itr != lhs.end(); lhs_itr++, rhs_itr++)
		{
			if (*lhs_itr != *rhs_itr)
				return false;
		}
		return true;
	}

	/* operator!= */
	friend bool	operator!=(const map& lhs, const map& rhs)
	{
		return !(lhs == rhs);
	}

	/* operator< */
	friend bool	operator< (const map& lhs, const map& rhs)
	{
		return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	/* operator<= */
	friend	bool	operator<=(const map& lhs, const map& rhs)
	{
		return !(rhs < lhs);
	}

	/* operator> */
	friend	bool	operator>(const map& lhs, const map& rhs)
	{
		return rhs < lhs;
	}

	/* operator>= */
	friend	bool	operator>=(const map& lhs, const map& rhs)
	{
		return !(lhs < rhs);
	}

	/* swap */
	friend void	swap(map& lhs, map& rhs)	{ lhs.swap(rhs); }

private:
	typedef map_node<value_type, value_compare, allocator_type>	node_type;

	void		_alloc_nil()
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
