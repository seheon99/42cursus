/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:57:08 by seyu              #+#    #+#             */
/*   Updated: 2021/07/02 16:19:32 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_utils.h"

char	*ft_strncpy(char *dest, const char *src, unsigned int n)
{
	unsigned int idx;

	idx = -1;
	while (src[++idx] != '\0' && idx < n)
		dest[idx] = src[idx];
	while (idx < n)
		dest[idx++] = '\0';
	return (dest);
}
