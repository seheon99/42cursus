/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 22:19:01 by seyu              #+#    #+#             */
/*   Updated: 2020/04/21 22:37:53 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int character)
{
	size_t	idx;

	if (character == '\0')
		return ((char *)(str + ft_strlen(str)));
	idx = 0;
	while (str[idx])
		idx += 1;
	while (idx > 0)
	{
		idx -= 1;
		if ((unsigned char)str[idx] == (unsigned char)character)
			return ((char *)(str + idx));
	}
	return (0);
}
