/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 20:17:07 by seyu              #+#    #+#             */
/*   Updated: 2021/12/22 01:21:23 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	itr;

	itr = 0;
	while (itr < n && s1[itr] && s2[itr])
	{
		if (s1[itr] != s2[itr])
			break ;
		itr++;
	}
	if (itr == n)
		return (0);
	return ((unsigned char)s1[itr] - (unsigned char)s2[itr]);
}
