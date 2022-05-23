/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:16:39 by seyu              #+#    #+#             */
/*   Updated: 2020/11/05 00:18:40 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	idx;
	size_t	new_string_idx;
	char	*new_string;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	if (!(new_string = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (0);
	new_string_idx = 0;
	idx = 0;
	while (s1 && s1[idx])
		new_string[new_string_idx++] = s1[idx++];
	idx = 0;
	while (s2 && s2[idx])
		new_string[new_string_idx++] = s2[idx++];
	new_string[new_string_idx] = '\0';
	return (new_string);
}
