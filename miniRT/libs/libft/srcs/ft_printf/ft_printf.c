/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 14:43:41 by seyu              #+#    #+#             */
/*   Updated: 2020/10/31 20:49:43 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "holder.h"
#include "write.h"
#include "libft.h"
#include "ft_printf.h"

/*
** @return	Number of bytes written
*/

int	ft_printf(const char *format, ...)
{
	ssize_t		bytes_read;
	ssize_t		bytes_written;
	ssize_t		write_rtn;
	t_holder	*holder;
	va_list		ap;

	bytes_read = 0;
	bytes_written = 0;
	va_start(ap, format);
	while (format[bytes_read])
	{
		bytes_written += write_nonholder(format, &bytes_read);
		if (!format[bytes_read])
			break ;
		holder = new_holder(format, &ap, &bytes_read);
		if (!holder->type)
			bytes_written += write(1, format + bytes_read - 1, 1);
		if ((write_rtn = write_holder(holder)) < 0)
			return (-1);
		bytes_written += write_rtn;
		delete_holder(&holder);
	}
	va_end(ap);
	return (bytes_written);
}
