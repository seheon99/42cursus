/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:00:55 by seyu              #+#    #+#             */
/*   Updated: 2020/04/10 18:12:53 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	int		isincluded(char ch, char const *str)
{
	size_t	idx;

	if (!str)
		return (0);
	idx = 0;
	while (str[idx])
	{
		if (ch == str[idx])
			return (1);
		idx += 1;
	}
	return (0);
}

static size_t	get_start_idx(char const *str, char const *set)
{
	size_t	start_idx;

	start_idx = 0;
	while (isincluded(str[start_idx], set) && start_idx < ft_strlen(str))
		start_idx += 1;
	return (start_idx);
}

static size_t	get_end_idx(char const *str, char const *set)
{
	size_t	end_idx;

	end_idx = ft_strlen(str) - 1;
	while (isincluded(str[end_idx], set) && end_idx > 0)
		end_idx -= 1;
	return (end_idx + 1);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t	idx;
	size_t	start_idx;
	size_t	end_idx;
	char	*str_trimmed;

	if (!s1)
		return (0);
	start_idx = get_start_idx(s1, set);
	end_idx = get_end_idx(s1, set);
	if (!(str_trimmed = malloc(sizeof(char) *
			(start_idx > end_idx ? 1 : end_idx - start_idx + 1))))
		return (0);
	idx = 0;
	while (start_idx < end_idx)
		str_trimmed[idx++] = s1[start_idx++];
	str_trimmed[idx] = '\0';
	return (str_trimmed);
}
