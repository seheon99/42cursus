/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_chartype.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 20:28:34 by seyu              #+#    #+#             */
/*   Updated: 2020/10/27 21:27:51 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>

#include "libft.h"
#include "buffer.h"
#include "holder.h"
#include "write.h"
#include "utils.h"

static int	chartype_data_size(t_holder *holder)
{
	if (holder->length == LENGTH_L || holder->type == 'C')
		return (pf_convert_unicode_to_utf8(*(wint_t *)(holder->data), NULL));
	else
		return (1);
}

int			write_chartype(t_holder *holder)
{
	t_buffer	*buffer;
	int			data_size;

	data_size = chartype_data_size(holder);
	if (data_size == 0)
		return (-1);
	buffer = new_buffer(ft_llmax(holder->width, data_size));
	chartype_datapart(holder, data_size, buffer);
	chartype_filling(holder, data_size, buffer);
	return (buffer_print(&buffer));
}
