/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   holder_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 12:16:16 by seyu              #+#    #+#             */
/*   Updated: 2020/07/19 20:24:42 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>

#include "holder.h"

void	*holder_data(va_list *ap, int length, int type)
{
	if (type_isinttype(type))
	{
		if (type == 'D' || type == 'O' || type == 'U')
			return (data_set_inttype(ap, LENGTH_L));
		else if (type == 'p')
			return (data_set_inttype(ap, LENGTH_LL));
		return (data_set_inttype(ap, length));
	}
	else if (type_isrealtype(type))
		return (data_set_realtype(ap));
	else if (type_ischartype(type) && type != '%')
		return (data_set_chartype(ap, (type == 'C' ? LENGTH_L : length)));
	else if (type_isstrtype(type))
		return (data_set_strtype(ap, (type == 'S' ? LENGTH_L : length)));
	else if (type == '%')
		return (NULL);
	return (NULL);
}
