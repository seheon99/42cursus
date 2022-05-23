/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 05:15:58 by seyu              #+#    #+#             */
/*   Updated: 2021/04/13 23:58:37 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<class T>
void	swap(T& arg1, T& arg2)
{
	T	temp;

	temp = arg1;
	arg1 = arg2;
	arg2 = temp;
}

template<class T>
T&		min(T& arg1, T& arg2)
{
	return (arg1 < arg2 ? arg1 : arg2);
}

template<class T>
T&		max(T& arg1, T& arg2)
{
	return (arg1 > arg2 ? arg1 : arg2);
}

#endif
