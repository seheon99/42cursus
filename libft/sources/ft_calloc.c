/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:07:26 by seyu              #+#    #+#             */
/*   Updated: 2021/12/21 21:11:41 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*memory;
	size_t	itr;

	memory = malloc(nmemb * size);
	itr = 0;
	while (itr < size)
	{
		((char *)memory)[itr] = '\0';
		itr++;
	}
	return (memory);
}
