/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtype_datapart.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 16:48:04 by seyu              #+#    #+#             */
/*   Updated: 2020/07/19 17:30:16 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>

#include "../holder/holder.h"
#include "../buffer/buffer.h"
#include "../libft/libft.h"
#include "write.h"

int	strtype_datapart(t_holder *holder, int data_size, t_buffer *buf)
{
	int	str_idx;
	int	str_itr;
	int	wcs_itr;

	str_idx = (holder->flags & FLAG_MINUS ? 0 : buf->size - data_size);
	if (holder->length == LENGTH_L || holder->type == 'S')
	{
		str_itr = 0;
		wcs_itr = 0;
		while (str_itr < data_size)
		{
			str_itr += ft_convert_unicode_to_utf8(
					(*(wchar_t **)(holder->data))[wcs_itr++],
					buf->buf + str_idx + str_itr);
		}
	}
	else
		ft_memcpy(buf->buf + str_idx, *(char **)(holder->data), data_size);
	return (data_size);
}
