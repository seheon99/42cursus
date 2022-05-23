/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpop_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 04:31:46 by seyu              #+#    #+#             */
/*   Updated: 2020/12/07 04:38:30 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

char
	ft_strpop(char **str)
{
	char	*dup;
	char	pop;

	pop = (*str)[0];
	dup = ft_strdup(*str + 1);
	free(*str);
	*str = dup;
	return (pop);
}
