/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 19:41:55 by seyu              #+#    #+#             */
/*   Updated: 2021/12/26 17:16:00 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	itr;

	itr = 0;
	while (itr + 1 < size && src[itr] != '\0')
	{
		dst[itr] = src[itr];
		itr++;
	}
	if (size != 0)
		dst[itr] = '\0';
	return (ft_strlen(src));
}
