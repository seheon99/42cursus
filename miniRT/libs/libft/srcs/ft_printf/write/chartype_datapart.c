/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chartype_datapart.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 20:47:56 by seyu              #+#    #+#             */
/*   Updated: 2020/10/27 21:27:25 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>

#include "holder.h"
#include "buffer.h"
#include "libft.h"
#include "write.h"
#include "utils.h"

int	chartype_datapart(t_holder *holder, int data_size, t_buffer *buf)
{
	int	char_idx;

	if (data_size == 0 || !holder || !buf)
		return (0);
	char_idx = (holder->flags & FLAG_MINUS ? 0 : buf->size - data_size);
	if (holder->type == '%')
		(buf->buf)[char_idx] = '%';
	else if (holder->length == LENGTH_L || holder->type == 'C')
		pf_convert_unicode_to_utf8(
				data_get_chartype(holder), buf->buf + char_idx);
	else
		(buf->buf)[char_idx] = data_get_chartype(holder);
	return (data_size);
}
