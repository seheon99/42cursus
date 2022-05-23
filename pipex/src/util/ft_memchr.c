/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:46:07 by seyu              #+#    #+#             */
/*   Updated: 2021/07/02 16:21:43 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_utils.h"

void	*ft_memchr(const void *space, int constant, size_t size)
{
	size_t	idx;

	idx = 0;
	while (idx < size)
	{
		if (((unsigned char *)space)[idx] == (unsigned char)constant)
			return ((char *)space + idx);
		idx += 1;
	}
	return (0);
}
