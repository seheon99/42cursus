/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:02:15 by seyu              #+#    #+#             */
/*   Updated: 2021/07/09 08:45:59 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

# include "utility.hpp"

# include "iterator.hpp"
# include "reverse_iterator.hpp"

namespace	ft
{

template <	typename Node, bool Constant >
class	map_iterator
{
public:
	typedef bidirectional_iterator_tag		iterator_category;
	typedef typename Node::value_type		value_type;
	typedef typename Node::difference_type	difference_type;
	typedef typename conditional<Constant, const value_type*, value_type*>::type
											pointer;
	typedef typename conditional<Constant, const value_type&, value_type&>::type
											reference;

	typedef Node			node;
	typedef map_iterator	iterator;

	map_iterator() : _ptr(NULL) {}
	map_iterator(const map_iterator<Node, false>& other) { _ptr = other.get_node(); }
	explicit map_iterator(node *const ptr) : _ptr(ptr) {}
	~map_iterator() {}

	iterator&	operator=(const iterator& other)
	{
		if (*this != other)
			_ptr = other._ptr;
		return (*this);
	}

	reference	operator*() const	{ return *(_ptr->value); }
	pointer		operator->() const	{ return (_ptr->value); }

	iterator&	operator++()	{ _ptr = _ptr->next(); return (*this); }
	iterator	operator++(int)	{ iterator itr = *this; ++(*this); return (itr); }

	iterator&	operator--()	{ _ptr = _ptr->prev(); return (*this); }
	iterator	operator--(int)	{ iterator itr = *this; --(*this); return (itr); }

	bool		operator==(const iterator& other) const	{ return (this->_ptr == other._ptr); }
	bool		operator!=(const iterator& other) const	{ return !(*this == other); }

	node*		get_node() const	{ return _ptr; }

private:
	node*		_ptr;
};

}

#endif
