/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:20:17 by seyu              #+#    #+#             */
/*   Updated: 2020/04/21 22:15:21 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int constant, size_t size)
{
	size_t	idx;

	idx = 0;
	while (idx < size)
	{
		((char *)dst)[idx] = ((char *)src)[idx];
		if (((unsigned char *)dst)[idx] == (unsigned char)constant)
			return ((char *)dst + idx + 1);
		idx += 1;
	}
	return (0);
}
