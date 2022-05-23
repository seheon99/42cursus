/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 20:35:32 by seyu              #+#    #+#             */
/*   Updated: 2021/12/21 21:31:06 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	size_t	itr;

	little_len = ft_strlen(little);
	if (little_len > len)
		return (NULL);
	itr = 0;
	while (itr < len - little_len)
	{
		if (ft_strncmp(big + itr, little, little_len) == 0)
			return ((char *)big + itr);
		itr++;
	}
	return (NULL);
}
