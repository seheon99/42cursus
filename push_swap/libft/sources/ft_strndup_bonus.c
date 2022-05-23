/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:26:17 by seyu              #+#    #+#             */
/*   Updated: 2020/12/06 16:52:40 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strndup(const char *str, size_t n)
{
	char	*dup;

	if (ft_strlen(str) < n)
		return (ft_strdup(str));
	dup = malloc(sizeof(char) * (n + 1));
	ft_strlcpy(dup, str, n + 1);
	return (dup);
}
