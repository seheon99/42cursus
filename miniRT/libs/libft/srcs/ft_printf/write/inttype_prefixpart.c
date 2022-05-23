/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inttype_prefixpart.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 09:26:02 by seyu              #+#    #+#             */
/*   Updated: 2020/10/27 21:27:04 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "holder.h"
#include "buffer.h"
#include "write.h"

static int	prefixpart_di(t_holder *holder, char *buf)
{
	ssize_t		data;

	data = data_get_inttype(holder);
	if (data < 0 || holder->flags & (FLAG_PLUS | FLAG_BLANK))
	{
		if (data < 0)
			buf[0] = '-';
		else if (holder->flags & FLAG_PLUS)
			buf[0] = '+';
		else if (holder->flags & FLAG_BLANK)
			buf[0] = ' ';
		return (1);
	}
	return (0);
}

static int	prefixpart_x(t_holder *holder, char *buf)
{
	size_t	data;

	data = data_get_inttype(holder);
	if (data != 0 && holder->flags & FLAG_HASH)
	{
		if (holder->type == 'X')
			ft_memcpy(buf, "0X", 2);
		else
			ft_memcpy(buf, "0x", 2);
		return (2);
	}
	return (0);
}

static int	prefixpart_p(t_holder *holder, char *buf)
{
	if (holder->type == 'p')
		ft_memcpy(buf, "0x", 2);
	return (2);
}

int			inttype_prefixpart(t_holder *holder,
					int prefix_size,
					int data_size,
					t_buffer *buf)
{
	int	prefix_idx;

	prefix_idx = (holder->flags & (FLAG_MINUS | FLAG_ZERO)
						? 0 : buf->size - data_size - prefix_size);
	if (holder->type == 'd' || holder->type == 'i' || holder->type == 'D')
		return (prefixpart_di(holder, buf->buf + prefix_idx));
	else if (holder->type == 'x' || holder->type == 'X')
		return (prefixpart_x(holder, buf->buf + prefix_idx));
	else if (holder->type == 'p')
		return (prefixpart_p(holder, buf->buf + prefix_idx));
	else
		return (0);
}
