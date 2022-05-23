/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:32:01 by seyu              #+#    #+#             */
/*   Updated: 2020/04/29 04:13:04 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	size_t	next_point(char const *str, char ch, int current_point)
{
	if (str[current_point == ch])
		while (str[current_point] && str[current_point] == ch)
			current_point += 1;
	else
		while (str[current_point] && str[current_point] != ch)
			current_point += 1;
	return (current_point);
}

static	size_t	count_split(char const *str, char ch)
{
	size_t	count;
	size_t	idx;

	count = 0;
	idx = next_point(str, ch, 0);
	while (str && str[idx])
	{
		while (str[idx] && str[idx] != ch)
			idx += 1;
		while (str[idx] && str[idx] == ch)
			idx += 1;
		count += 1;
	}
	return (count + 1);
}

char			**ft_split(char const *s, char c)
{
	char	**array;
	size_t	array_idx;
	size_t	start;
	size_t	end;
	size_t	count;

	if (!s)
		return (0);
	count = count_split(s, c);
	if (!(array = malloc(sizeof(char *) * count)))
		return (0);
	array_idx = 0;
	end = 0;
	while (s && array_idx < count - 1)
	{
		if (!s[start = next_point(s, c, end)])
			break ;
		end = start + 1;
		while (s[end] && s[end] != c)
			end += 1;
		array[array_idx] = malloc(sizeof(char) * (end - start + 1));
		ft_strlcpy(array[array_idx++], s + start, end - start + 1);
	}
	array[array_idx] = NULL;
	return (array);
}
