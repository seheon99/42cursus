/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 22:52:09 by seyu              #+#    #+#             */
/*   Updated: 2021/05/01 19:10:27 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	idx;
	size_t	little_len;

	if (!big && !little)
		return ((char *)big);
	if (ft_strlen(big) < len)
		len = ft_strlen(big);
	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	idx = 0;
	while (idx + little_len - 1 < len)
	{
		if (!ft_strncmp(big + idx, little, little_len))
			return ((char *)(big + idx));
		idx += 1;
	}
	return (0);
}
