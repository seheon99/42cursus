/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 15:13:41 by seyu              #+#    #+#             */
/*   Updated: 2021/05/01 21:11:42 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char
	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	idx;
	char	*str;

	if (!s || !f)
		return (0);
	str = malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (str == NULL)
		return (str);
	idx = 0;
	while (s[idx])
	{
		str[idx] = f(idx, s[idx]);
		idx += 1;
	}
	str[idx] = '\0';
	return (str);
}
