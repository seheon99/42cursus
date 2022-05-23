/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 19:51:38 by seyu              #+#    #+#             */
/*   Updated: 2021/12/26 17:04:42 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	rtn;
	size_t	itr;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (size <= dstlen)
		rtn = srclen + size;
	else
		rtn = srclen + dstlen;
	itr = 0;
	while (dstlen + 1 < size && src[itr] != '\0')
		dst[dstlen++] = src[itr++];
	dst[dstlen] = '\0';
	return (rtn);
}
