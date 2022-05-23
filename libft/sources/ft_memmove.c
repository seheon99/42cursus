/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 19:26:50 by seyu              #+#    #+#             */
/*   Updated: 2021/12/22 01:10:13 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	itr;

	if (dst == src)
		return (dst);
	itr = 0;
	while (itr < n)
	{
		if (dst < src)
			((char *)dst)[itr] = ((char *)src)[itr];
		else if (dst > src)
			((char *)dst)[n - itr - 1] = ((char *)src)[n - itr - 1];
		itr++;
	}
	return (dst);
}
