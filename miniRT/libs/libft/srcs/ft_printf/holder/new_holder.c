/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_holder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 15:30:58 by seyu              #+#    #+#             */
/*   Updated: 2020/08/05 09:55:10 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "holder.h"

static void	holder_revise_prec(t_holder *holder)
{
	if (type_isinttype(holder->type) && holder->prec == -2)
		holder->prec = 1;
	else if (holder->type == 'g' && holder->prec == 0)
		holder->prec = 1;
	else if (type_isrealtype(holder->type) && holder->prec == -2)
		holder->prec = 6;
	else if (type_isinttype(holder->type))
		holder->flags &= ~FLAG_ZERO;
}

static void	holder_revise_width(t_holder *holder)
{
	if (holder->width < 0)
	{
		holder->width = -(holder->width);
		holder->flags |= FLAG_MINUS;
	}
}

t_holder	*new_holder(const char *format, va_list *ap, ssize_t *bytes_read)
{
	t_holder	*holder;
	ssize_t		start_bytes;

	if (!bytes_read || !format || format[(*bytes_read)++] != '%' || !ap)
		return (NULL);
	start_bytes = *bytes_read;
	holder = malloc(sizeof(t_holder));
	*bytes_read += holder_flags(format + *bytes_read, &(holder->flags));
	*bytes_read += holder_width(format + *bytes_read, &(holder->width), ap);
	*bytes_read += holder_prec(format + *bytes_read, &(holder->prec), ap);
	*bytes_read += holder_length(format + *bytes_read, &(holder->length));
	*bytes_read += holder_type(format + *bytes_read, &(holder->type));
	holder->data = NULL;
	if (holder->type)
		holder->data = holder_data(ap, holder->length, holder->type);
	else
		*bytes_read = start_bytes;
	holder_revise_width(holder);
	holder_revise_prec(holder);
	return (holder);
}
