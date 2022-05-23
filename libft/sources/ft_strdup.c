/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:12:12 by seyu              #+#    #+#             */
/*   Updated: 2021/12/21 21:19:58 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	str_len;
	char	*dupped_str;
	size_t	itr;

	str_len = ft_strlen(str);
	dupped_str = malloc(sizeof(char) * (str_len + 1));
	itr = 0;
	while (itr < str_len)
	{
		dupped_str[itr] = str[itr];
		itr++;
	}
	dupped_str[itr] = '\0';
	return (dupped_str);
}
