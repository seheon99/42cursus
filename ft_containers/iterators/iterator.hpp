/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 20:09:35 by seyu              #+#    #+#             */
/*   Updated: 2021/06/28 04:36:02 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef>

# include "type_traits.hpp"

namespace	ft
{

struct	input_iterator_tag {};
struct	output_iterator_tag {};
struct	forward_iterator_tag : public input_iterator_tag {};
struct	bidirectional_iterator_tag : public forward_iterator_tag {};
struct	random_access_iterator_tag : public bidirectional_iterator_tag {};

template <	typename Iterator >
struct	iterator_traits
{
	typedef typename Iterator::iterator_category	iterator_category;
	typedef typename Iterator::value_type			value_type;
	typedef typename Iterator::difference_type		difference_type;
	typedef typename Iterator::pointer				pointer;
	typedef typename Iterator::reference			reference;
};

template <	typename T >
struct	iterator_traits<T*>
{
	typedef random_access_iterator_tag	iterator_category;
	typedef T							value_type;
	typedef ptrdiff_t					difference_type;
	typedef T*							pointer;
	typedef T&							reference;
};

template <	typename Category,
			typename T,
			typename Distance = ptrdiff_t,
			typename Pointer = T*,
			typename Reference = T& >
struct	iterator
{
	typedef Category	iterator_category;
	typedef T			value_type;
	typedef Distance	difference_type;
	typedef Pointer		pointer;
	typedef Reference	reference;
};

namespace	detail
{

template <	typename Iterator >
void	do_advance(Iterator& itr, typename iterator_traits<Iterator>::difference_type n, input_iterator_tag)
{
	while (--n > 0)
		itr++;
}

template <	typename Iterator >
void	do_advance(Iterator& itr, typename iterator_traits<Iterator>::difference_type n, bidirectional_iterator_tag)
{
	while (n > 0)
	{
		n--;
		itr++;
	}
	while (n < 0)
	{
		n++;
		itr--;
	}
}

template <	typename Iterator >
void	do_advance(Iterator& itr, typename iterator_traits<Iterator>::difference_type n, random_access_iterator_tag)
{
	itr += n;
}

template <	typename Iterator >
typename iterator_traits<Iterator>::difference_type
	do_distance(Iterator first, Iterator last, input_iterator_tag)
{
	typename iterator_traits<Iterator>::difference_type	result = 0;

	while (first != last)
	{
		++first;
		++result;
	}
	return (result);
}

template <	typename Iterator >
typename iterator_traits<Iterator>::difference_type
	do_distance(Iterator first, Iterator last, random_access_iterator_tag)
{
	return (last - first);
}

} // namespace detail

template <	typename Iterator, typename Distance >
void	advance(Iterator& itr, Distance n)
{
	detail::do_advance(itr, typename ft::iterator_traits<Iterator>::difference_type(n), typename ft::iterator_traits<Iterator>::iterator_category());
}

template <	typename Iterator >
typename iterator_traits<Iterator>::difference_type
	distance(Iterator first, Iterator last)
{
	return (detail::do_distance(first, last, typename ft::iterator_traits<Iterator>::iterator_category()));
}

}

#endif
