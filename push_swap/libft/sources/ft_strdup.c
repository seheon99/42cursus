/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 00:06:40 by seyu              #+#    #+#             */
/*   Updated: 2021/05/01 21:02:09 by seyu             ###   ########.fr       */
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
	memory = malloc(sizeof(char) * (idx + 1));
	if (memory == NULL)
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
