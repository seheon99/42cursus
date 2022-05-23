/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_set_chartype.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 12:24:47 by seyu              #+#    #+#             */
/*   Updated: 2020/07/19 18:08:58 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <stdlib.h>

#include "holder.h"

void	*data_set_chartype(va_list *ap, int length)
{
	void	*data;

	if (length == LENGTH_L)
	{
		data = malloc(sizeof(wint_t));
		*(wint_t *)data = va_arg(*ap, wint_t);
	}
	else
	{
		data = malloc(sizeof(char));
		*(char *)data = (char)va_arg(*ap, int);
	}
	return (data);
}
