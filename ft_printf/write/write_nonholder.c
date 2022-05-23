/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_nonholder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 09:06:34 by seyu              #+#    #+#             */
/*   Updated: 2020/07/25 19:04:55 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <unistd.h>

ssize_t	write_nonholder(const char *format, ssize_t *bytes_read)
{
	ssize_t	bytes_written;

	bytes_written = 0;
	while (format[*bytes_read + bytes_written])
	{
		if (format[*bytes_read + bytes_written] == '%')
			break ;
		bytes_written += 1;
	}
	write(1, format + *bytes_read, bytes_written);
	*bytes_read += bytes_written;
	return (bytes_written);
}
