/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 23:25:23 by seyu              #+#    #+#             */
/*   Updated: 2020/04/21 22:38:35 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t idx;

	idx = 0;
	if (!s1 && !s2)
		return (0);
	if (n == 0)
		return (0);
	while (s1[idx] == s2[idx] && s1[idx] != '\0' && s2[idx] != '\0')
	{
		if (++idx == n)
			return (0);
	}
	return ((unsigned char)s1[idx] - (unsigned char)s2[idx]);
}
