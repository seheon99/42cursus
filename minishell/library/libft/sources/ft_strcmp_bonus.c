/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 00:59:19 by seyu              #+#    #+#             */
/*   Updated: 2020/12/01 01:01:35 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t idx;

	idx = 0;
	if (!s1 && !s2)
		return (0);
	while (s1[idx] == s2[idx] && s1[idx] != '\0' && s2[idx] != '\0')
		idx++;
	return ((unsigned char)s1[idx] - (unsigned char)s2[idx]);
}
