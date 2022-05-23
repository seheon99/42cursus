/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:39:14 by seyu              #+#    #+#             */
/*   Updated: 2020/04/17 15:45:07 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void *src, size_t size)
{
	size_t	idx;

	if (!dst && !src)
		return (NULL);
	idx = 0;
	while (idx < size)
	{
		((char *)dst)[idx] = ((char *)src)[idx];
		idx += 1;
	}
	return (dst);
}
