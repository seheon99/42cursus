/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_set_inttype.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 12:16:30 by seyu              #+#    #+#             */
/*   Updated: 2020/07/19 20:13:16 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>

#include "holder.h"

void	*inttype_length(va_list *ap, int length)
{
	void	*rtn;

	rtn = NULL;
	if (length == LENGTH_HH)
	{
		rtn = malloc(sizeof(char));
		*(char *)rtn = (char)va_arg(*ap, int);
	}
	else if (length == LENGTH_H)
	{
		rtn = malloc(sizeof(short));
		*(short *)rtn = (short)va_arg(*ap, int);
	}
	else if (length == LENGTH_L)
	{
		rtn = malloc(sizeof(long));
		*(long *)rtn = va_arg(*ap, long);
	}
	else if (length == LENGTH_LL)
	{
		rtn = malloc(sizeof(long long));
		*(long long *)rtn = va_arg(*ap, long long);
	}
	return (rtn);
}

void	*data_set_inttype(va_list *ap, int length)
{
	void	*rtn;

	if (length > NOLENGTH)
		return (inttype_length(ap, length));
	else
	{
		rtn = malloc(sizeof(int));
		*(int *)rtn = va_arg(*ap, int);
	}
	return (rtn);
}
