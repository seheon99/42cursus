/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 20:28:21 by seyu              #+#    #+#             */
/*   Updated: 2021/12/22 01:09:06 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	itr;

	itr = 0;
	while (itr < n)
	{
		if (((unsigned char *)s1)[itr] != ((unsigned char *)s2)[itr])
			return (((unsigned char *)s1)[itr] - ((unsigned char *)s2)[itr]);
		itr++;
	}
	return (0);
}
