/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:38:53 by seyu              #+#    #+#             */
/*   Updated: 2020/04/28 20:25:25 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t dest_size;
	size_t src_size;
	size_t idx;

	dest_size = ft_strlen(dest);
	src_size = ft_strlen(src);
	idx = 0;
	if (size <= dest_size)
		src_size = src_size + size;
	else
		src_size = src_size + dest_size;
	while (src[idx] != '\0' && dest_size + 1 < size)
	{
		dest[dest_size] = src[idx];
		dest_size++;
		idx++;
	}
	dest[dest_size] = '\0';
	return (src_size);
}
