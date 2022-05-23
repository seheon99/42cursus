/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnpop_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 16:39:07 by seyu              #+#    #+#             */
/*   Updated: 2020/12/06 16:59:27 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

char
	*ft_strnpop(char **str, size_t n)
{
	char	*pop_str;
	char	*temp;

	pop_str = ft_strndup(*str, n);
	temp = *str;
	if (ft_strlen(*str) < n)
		*str = ft_strdup("");
	else
		*str = ft_strdup(*str + n);
	free(temp);
	return (pop_str);
}
