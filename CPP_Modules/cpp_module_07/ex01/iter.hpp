/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 06:09:50 by seyu              #+#    #+#             */
/*   Updated: 2021/04/13 23:59:00 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template<class T>
void
	iter(T* array, int length, void (*func)(T& elem))
{
	if (array == NULL || func == NULL)
		return ;
	for (int i = 0; i < length; i++)
		func(array[i]);
}

#endif
