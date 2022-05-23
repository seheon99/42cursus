/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 15:31:21 by seyu              #+#    #+#             */
/*   Updated: 2021/07/09 17:16:23 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_ITERATOR_HPP
# define SET_ITERATOR_HPP

# include "utility.hpp"

# include "iterator.hpp"
# include "reverse_iterator.hpp"

namespace	ft
{

template <	typename Node, bool Constant >
class	set_iterator
{
public:
	typedef bidirectional_iterator_tag		iterator_category;
	typedef const typename Node::value_type	value_type;
	typedef typename Node::difference_type	difference_type;
	typedef value_type*						pointer;
	typedef value_type&						reference;

	typedef Node			node;
	typedef set_iterator	iterator;

	set_iterator() : _ptr(NULL) {}
	set_iterator(const set_iterator<Node, false>& other) { _ptr = other.get_node(); }
	explicit set_iterator(node *const ptr) : _ptr(ptr) {}
	~set_iterator() {}

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
	node*	_ptr;
};

}

#endif
