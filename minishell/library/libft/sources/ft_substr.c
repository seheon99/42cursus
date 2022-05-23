/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:03:03 by seyu              #+#    #+#             */
/*   Updated: 2020/04/26 07:43:20 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	malloc_size;
	char	*substr;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		malloc_size = 1;
	else if (ft_strlen(s) - start + 1 < len)
		malloc_size = ft_strlen(s) - start + 1;
	else
		malloc_size = len + 1;
	if (!(substr = malloc(sizeof(char) * malloc_size)))
		return (NULL);
	ft_strlcpy(substr, s + start, malloc_size);
	return (substr);
}
