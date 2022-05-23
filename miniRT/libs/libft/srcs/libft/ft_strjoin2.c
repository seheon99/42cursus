/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 00:21:36 by seyu              #+#    #+#             */
/*   Updated: 2020/11/05 00:43:59 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

char		*ft_strjoin2(char **s1, char const *s2)
{
	char	*join_tmp;

	join_tmp = ft_strjoin(*s1, s2);
	free (*s1);
	*s1 = join_tmp;
	return (*s1);
}
