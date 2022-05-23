/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inttype_filling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 11:58:30 by seyu              #+#    #+#             */
/*   Updated: 2020/10/27 21:27:04 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "holder.h"
#include "buffer.h"
#include "write.h"

int	inttype_filling(t_holder *holder,
			int prefix_size,
			int data_size,
			t_buffer *buf)
{
	int		filling_size;
	int		filling_idx;
	char	filling_ch;
	int		itr;

	filling_size = buf->size - prefix_size - data_size;
	filling_idx = (holder->flags & FLAG_ZERO ? prefix_size : 0);
	if (holder->flags & FLAG_MINUS)
		filling_idx = prefix_size + data_size;
	filling_ch = (holder->flags & FLAG_ZERO ? '0' : ' ');
	if (holder->flags & FLAG_MINUS)
		filling_ch = ' ';
	itr = -1;
	while (++itr < filling_size)
		(buf->buf)[filling_idx + itr] = filling_ch;
	return (filling_size);
}
