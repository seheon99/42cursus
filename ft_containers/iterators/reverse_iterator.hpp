/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 13:14:33 by seyu              #+#    #+#             */
/*   Updated: 2021/06/30 04:33:18 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator.hpp"

namespace	ft
{

template <	typename Iterator >
class	reverse_iterator
{
public:
	typedef Iterator												iterator_type;
	typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
	typedef typename iterator_traits<Iterator>::value_type			value_type;
	typedef typename iterator_traits<Iterator>::difference_type		difference_type;
	typedef typename iterator_traits<Iterator>::pointer				pointer;
	typedef typename iterator_traits<Iterator>::reference			reference;

	reverse_iterator() : _current() {}
	explicit reverse_iterator(iterator_type x) : _current(x) {}

	template <	typename U >
	reverse_iterator(const reverse_iterator<U>& u) : _current(u.base()) {}

	template <	typename U >
	reverse_iterator&	operator=(const reverse_iterator<U>& u)	{ _current = u.base(); return (*this); }

	iterator_type		base() const { return _current; }

	reference			operator*() const	{ return (*_current); }
	pointer				operator->() const	{ return &(*_current); }

	reference			operator[](difference_type n) const	{ return *(*this + n); }

	reverse_iterator&	operator++()		{ --_current; return (*this); }
	reverse_iterator	operator++(int)		{ reverse_iterator tmp(*this); --_current; return (tmp); }
	reverse_iterator&	operator+=(difference_type n) const	{ _current -= n; return (*this); }
	reverse_iterator&	operator--()		{ ++_current; return (*this); }
	reverse_iterator	operator--(int)		{ reverse_iterator tmp(*this); ++_current; return (tmp); }
	reverse_iterator&	operator-=(difference_type n)		{ _current += n; return (*this); }
	reverse_iterator	operator-(difference_type n) const	{ return reverse_iterator(_current + n); }

	/* ---------------------------------------- */
	/*           Non-member functions           */
	/* ---------------------------------------- */

	template <	typename RIterator>
	friend	bool operator==(const reverse_iterator<iterator_type>& lhs, const reverse_iterator<RIterator>& rhs)
	{
		return (lhs._current == rhs._current);
	}

	template <	typename RIterator>
	friend	bool operator!=(const reverse_iterator<iterator_type>& lhs, const reverse_iterator<RIterator>& rhs)
	{
		return (lhs._current != rhs._current);
	}

	template <	typename RIterator>
	friend	bool operator<(const reverse_iterator<iterator_type>& lhs, const reverse_iterator<RIterator>& rhs)
	{
		return (lhs._current > rhs._current);
	}

	template <	typename RIterator>
	friend	bool operator<=(const reverse_iterator<iterator_type>& lhs, const reverse_iterator<RIterator>& rhs)
	{
		return (lhs._current >= rhs._current);
	}

	template <	typename RIterator>
	friend	bool operator>(const reverse_iterator<iterator_type>& lhs, const reverse_iterator<RIterator>& rhs)
	{
		return (lhs._current < rhs._current);
	}

	template <	typename RIterator>
	friend	bool operator>=(const reverse_iterator<iterator_type>& lhs, const reverse_iterator<RIterator>& rhs)
	{
		return (lhs._current <= rhs._current);
	}

	friend	reverse_iterator<iterator_type> operator+(typename reverse_iterator<iterator_type>::difference_type n, const reverse_iterator<iterator_type>& it)
	{
		return (reverse_iterator<iterator_type>(it._current - n));
	}

	friend	typename reverse_iterator<iterator_type>::difference_type
		operator-(const reverse_iterator<iterator_type>& lhs, const reverse_iterator<iterator_type>& rhs)
	{
		return (rhs._current - lhs._current);
	}

private:
	iterator_type	_current;
};


}

#endif
