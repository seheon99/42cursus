/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 23:51:26 by seyu              #+#    #+#             */
/*   Updated: 2020/12/08 02:07:08 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

int	ft_append(char **dest, const char *src)
{
	char	*joinstr;

	if (!dest || !src)
		return (-1);
	if (!(*dest))
	{
		*dest = ft_strdup(src);
		return (0);
	}
	joinstr = ft_strjoin(*dest, src);
	free(*dest);
	*dest = joinstr;
	return (0);
}
