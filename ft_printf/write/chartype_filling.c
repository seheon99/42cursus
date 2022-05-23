/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chartype_filling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 20:54:24 by seyu              #+#    #+#             */
/*   Updated: 2020/07/19 17:08:19 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>

#include "../holder/holder.h"
#include "../buffer/buffer.h"
#include "write.h"

int	chartype_filling(t_holder *holder, int data_size, t_buffer *buf)
{
	char	filling_ch;
	int		filling_idx;
	int		filling_size;
	int		itr;

	filling_ch = (holder->flags & FLAG_ZERO ? '0' : ' ');
	if (holder->flags & FLAG_MINUS)
		filling_ch = ' ';
	filling_idx = (holder->flags & FLAG_MINUS ? data_size : 0);
	filling_size = buf->size - data_size;
	itr = -1;
	while (++itr < filling_size)
		(buf->buf)[filling_idx + itr] = filling_ch;
	return (filling_size);
}
