/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 00:02:33 by seyu              #+#    #+#             */
/*   Updated: 2021/01/22 03:45:21 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			idx;
	unsigned char	*memory;

	memory = malloc(nmemb * size);
	if (!memory)
		return (0);
	idx = 0;
	while (idx < nmemb * size)
		memory[idx++] &= 0;
	return ((void *)memory);
}
