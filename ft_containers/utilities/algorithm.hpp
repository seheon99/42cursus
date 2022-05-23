/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 04:26:09 by seyu              #+#    #+#             */
/*   Updated: 2021/07/06 00:39:37 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_HPP
# define ALGORITHM_HPP

namespace	ft
{

//	@param p:	binary predicate which returns true if
//					the elements should be treated as equal

//	equal(InputIt1 first, InputIt1 last1, InputIt2 first2):
//	Returns true if
//		the range [first1, last1) is equal to
//		the range [first2, first2 + (last1 - first1))
//	and false otherwise

template <	typename InputIt1, typename InputIt2 >
bool	equal(InputIt1 first1, InputIt1 last1, InputIt2 first2)
{
	while (first1 != last1)
	{
		if (*first1++ != *first2++)
			return (false);
	}
	return (true);
}

template <	typename InputIt1, typename InputIt2, typename BinaryPredicate >
bool	equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p)
{
	while (first1 != last1)
	{
		if (p(*first1++, *first2++) == false)
			return (false);
	}
	return (true);
}

//	equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2):
//	Returns true if
//		the range [first1, last1) is equal to
//		the range [first2, last2)
//	and false otherwise

template <	typename InputIt1, typename InputIt2 >
bool	equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
{
	while (first1 != last1 && first2 != last2)
	{
		if (*first1++ != *first2++)
			return (false);
	}
	if (first1 == last1 && first2 == last2)
		return (true);
	return (false);
}

template <	typename InputIt1, typename InputIt2, typename BinaryPredicate >
bool	equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, BinaryPredicate p)
{
	while (first1 != last1 && first2 != last2)
	{
		if (p(*first1++, *first2++) == false)
			return (false);
	}
	if (first1 == last1 && first2 == last2)
		return (true);
	return (false);
}

template <	typename InputIt1, typename InputIt2 >
bool	lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
{
	for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 )
	{
		if (*first1 < *first2)	return true;
		if (*first2 < *first1)	return false;
	}
	return (first1 == last1) && (first2 != last2);
}

template <	typename InputIt1, typename InputIt2, typename Compare >
bool	lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp)
{
	for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 )
	{
		if (comp(*first1, *first2))	return true;
		if (comp(*first2, *first1))	return false;
	}
	return (first1 == last1) && (first2 != last2);
}

template <	typename T >
void	swap(T& a, T& b)
{
	T	temp;

	temp = a;
	a = b;
	b = temp;
}

}

#endif
