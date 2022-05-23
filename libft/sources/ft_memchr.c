/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 20:23:40 by seyu              #+#    #+#             */
/*   Updated: 2021/12/21 21:28:18 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int constant, size_t count)
{
	size_t	itr;

	itr = 0;
	while (itr < count)
	{
		if (((char *)buf)[itr] == constant)
			return ((char *)buf + itr);
		itr++;
	}
	return (NULL);
}
