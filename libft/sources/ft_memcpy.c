/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 19:21:44 by seyu              #+#    #+#             */
/*   Updated: 2021/12/21 19:25:56 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t size)
{
	size_t	itr;

	itr = 0;
	while (itr < size)
	{
		((char *)dst)[itr] = ((char *)src)[itr];
		itr++;
	}
	return (dst);
}
