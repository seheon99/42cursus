/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:17:24 by seyu              #+#    #+#             */
/*   Updated: 2020/04/25 21:24:05 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t idx;
	size_t src_size;

	if (!dst || !src)
		return (0);
	src_size = ft_strlen(src);
	if (size == 0)
		return (src_size);
	idx = 0;
	while (idx < size - 1 && src[idx] != '\0')
	{
		dst[idx] = src[idx];
		idx += 1;
	}
	dst[idx] = '\0';
	return (src_size);
}
