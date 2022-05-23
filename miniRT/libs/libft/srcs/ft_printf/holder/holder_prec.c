/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   holder_prec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 11:15:39 by seyu              #+#    #+#             */
/*   Updated: 2020/10/27 21:26:13 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include "libft.h"

int	holder_prec(const char *precpart, int *prec, va_list *ap)
{
	int	itr;

	if (prec)
		*prec = -2;
	if (!prec || !precpart || precpart[0] != '.')
		return (0);
	*prec = 0;
	itr = 1;
	if (precpart[itr] == '*')
	{
		if ((*prec = va_arg(*ap, int)) < 0)
			*prec = -2;
		itr += 1;
	}
	else
	{
		if (ft_isdigit(precpart[itr]))
			*prec = ft_atoi(precpart + itr);
		while (ft_isdigit(precpart[itr]))
			itr += 1;
	}
	return (itr);
}
