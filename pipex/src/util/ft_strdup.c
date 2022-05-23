/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 00:06:40 by seyu              #+#    #+#             */
/*   Updated: 2020/04/24 04:12:37 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	size_t	idx;
	char	*memory;

	idx = 0;
	while (str[idx])
		idx += 1;
	if (!(memory = malloc(sizeof(char) * (idx + 1))))
		return (0);
	idx = 0;
	while (str[idx])
	{
		memory[idx] = str[idx];
		idx += 1;
	}
	memory[idx] = '\0';
	return (memory);
}
