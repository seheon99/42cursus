/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 20:04:13 by seyu              #+#    #+#             */
/*   Updated: 2021/12/22 01:17:22 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int character)
{
	size_t	itr;

	if (character == '\0')
		return ((char *)str + ft_strlen(str));
	itr = 0;
	while (str[itr] != '\0')
	{
		if (str[itr] == character)
			return ((char *)str + itr);
		itr++;
	}
	return (NULL);
}
