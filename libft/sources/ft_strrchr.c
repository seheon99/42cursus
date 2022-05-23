/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 20:10:49 by seyu              #+#    #+#             */
/*   Updated: 2021/12/22 01:24:15 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int character)
{
	size_t	itr;

	itr = ft_strlen(str);
	while (1)
	{
		if (str[itr] == character)
			return ((char *)str + itr);
		else if (itr == 0)
			return (NULL);
		itr--;
	}
}
