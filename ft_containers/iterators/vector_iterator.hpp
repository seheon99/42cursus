/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 02:40:24 by seyu              #+#    #+#             */
/*   Updated: 2021/07/09 08:51:43 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include "vector_iterator.hpp"
# include "reverse_iterator.hpp"

namespace	ft
{

template <	typename Container, bool Constant >
class	vector_iterator
{
public:
	typedef random_access_iterator_tag				iterator_category;
	typedef typename Container::value_type			value_type;
	typedef typename Container::difference_type		difference_type;
	typedef typename conditional<Constant, const value_type*, value_type*>::type
													pointer;
	typedef typename conditional<Constant, const value_type&, value_type&>::type
													reference;

	vector_iterator() : _ptr(NULL) {}
	vector_iterator(const vector_iterator<Container, false>& other) { _ptr = &(*other); }
	explicit vector_iterator(pointer const ptr) : _ptr(ptr) {}
	~vector_iterator() {}

	vector_iterator&	operator=(const vector_iterator& other)
	{
		if (this != &other)
			_ptr = other._ptr;
		return (*this);
	}

	reference	operator*() const	{ return *_ptr; }
	pointer		operator->() const	{ return _ptr; }

	vector_iterator&	operator++()	{ _ptr++; return (*this); }
	vector_iterator		operator++(int)	{ vector_iterator itr = *this; ++(*this); return (itr); }

	vector_iterator&	operator--()	{ _ptr--; return (*this); }
	vector_iterator		operator--(int)	{ vector_iterator itr = *this; --(*this); return (itr); }

	bool		operator==(const vector_iterator& other) const	{ return (this->_ptr == other._ptr); }
	bool		operator!=(const vector_iterator& other) const	{ return !(*this == other); }
	bool		operator<(const vector_iterator& other) const	{ return (this->_ptr < other._ptr); }
	bool		operator<=(const vector_iterator& other) const	{ return !(*this > other); }
	bool		operator>(const vector_iterator& other) const	{ return (other < *this); }
	bool		operator>=(const vector_iterator& other) const	{ return !(*this < other); }

	vector_iterator	operator+=(difference_type n)	{ _ptr += n; return (*this); }
	vector_iterator	operator+(difference_type n)	{ vector_iterator itr = *this; itr += n; return (itr); }
	vector_iterator	operator-=(difference_type n)	{ _ptr -= n; return (*this); }
	vector_iterator	operator-(difference_type n)	{ vector_iterator itr = *this; itr -= n; return (itr); }

	reference		operator[](difference_type n) const	{ return _ptr[n]; }
	difference_type	operator-(vector_iterator other) const	{ return (this->_ptr - other._ptr); }

	friend		vector_iterator operator+(difference_type nb, const vector_iterator& itr)	{ vector_iterator rtn = itr; return (rtn += nb); }
private:
	pointer	_ptr;
};

// template <	typename Allocator, bool Constant >
// class	vector_iterator<vector<bool, Allocator>, Constant>
// {
// public:
// 	typedef random_access_iterator_tag							iterator_category;
// 	typedef typename set_const<bool, Constant>::type			value_type;
// 	typedef typename vector<bool, Allocator>::difference_type	difference_type;
// 	typedef typename vector<bool, Allocator>::pointer			pointer;
// 	typedef typename vector<bool, Allocator>::reference			reference;

// 	vector_iterator() : _data(NULL), _idx(0) {}
// 	vector_iterator(const vector_iterator<vector<bool, Allocator>, false>& other) { _data = other._data; _idx = other._idx; }
// 	explicit vector_iterator(typename Allocator::pointer const data, difference_type idx) : _data(data), _idx(idx) {}
// 	~vector_iterator() {}

// 	vector_iterator&	operator=(const vector_iterator& other)
// 	{
// 		if (this != &other)
// 		{
// 			_data = other._data;
// 			_idx = other._idx;
// 		}
// 		return (*this);
// 	}

// 	reference	operator*() const	{ return reference(_data, _idx); }

// 	vector_iterator&	operator++()	{ _idx++; return (*this); }
// 	vector_iterator		operator++(int)	{ vector_iterator itr = *this; ++(*this); return (itr); }

// 	vector_iterator&	operator--()	{ _idx--; return (*this); }
// 	vector_iterator		operator--(int) { vector_iterator itr = *this; --(*this); return (itr); }

// 	bool		operator==(const vector_iterator& other) const	{ return (this->_data == other._data && this->_idx == other._idx); }
// 	bool		operator!=(const vector_iterator& other) const	{ return !(*this == other); }
// 	bool		operator<(const vector_iterator& other) const
// 	{
// 		if (_data == other._data)
// 			return (_idx < other._idx);
// 		return (_data < other._data);
// 	}
// 	bool		operator<=(const vector_iterator& other) const	{ return !(*this > other); }
// 	bool		operator>(const vector_iterator& other) const	{ return (other < *this); }
// 	bool		operator>=(const vector_iterator& other) const	{ return !(*this < other); }

// 	vector_iterator	operator+=(difference_type n)	{ _idx += n; return (*this); }
// 	vector_iterator	operator+(difference_type n)	{ vector_iterator itr = *this; itr += n; return (itr); }
// 	vector_iterator	operator-=(difference_type n)	{ _idx -= n; return (*this); }
// 	vector_iterator	operator-(difference_type n)	{ vector_iterator itr = *this; itr -= n; return (itr); }

// 	reference		operator[](difference_type n) const	{ return reference(_data, _idx + n); }
// 	difference_type	operator-(vector_iterator other) const	{ return (this->_idx - other._idx); }

// 	friend	vector_iterator operator+(difference_type nb, const vector_iterator& itr)	{ return (itr + nb); }

// 	typename Allocator::pointer	_data;
// 	difference_type				_idx;

// private:
// 	typedef typename Allocator::pointer	base_pointer;
// 	static const typename vector<bool, Allocator>::size_type	_alloc_bitsize;
// };

// template <	typename Allocator, bool Constant >
// const typename vector<bool, Allocator>::size_type
// 	vector_iterator<vector<bool, Allocator>, Constant>::_alloc_bitsize = sizeof(Allocator::value_type) * 8;

}

#endif
