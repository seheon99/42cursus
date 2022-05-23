/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:46:06 by seyu              #+#    #+#             */
/*   Updated: 2020/04/21 22:34:52 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	idx;
	size_t	from_end;

	if (!dst && !src)
		return (dst);
	from_end = (unsigned long)dst > (unsigned long)src;
	idx = -1;
	while (++idx < n)
	{
		if (from_end)
			((char *)dst)[n - 1 - idx] = ((char *)src)[n - 1 - idx];
		else
			((char *)dst)[idx] = ((char *)src)[idx];
	}
	return (dst);
}
