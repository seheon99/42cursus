/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_inttype.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 10:27:59 by seyu              #+#    #+#             */
/*   Updated: 2020/10/27 21:27:04 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "holder.h"
#include "buffer.h"
#include "write.h"

static int	inttype_prefix_size(t_holder *holder)
{
	if (holder->type == 'd' || holder->type == 'i' || holder->type == 'D')
	{
		if ((ssize_t)data_get_inttype(holder) < 0
				|| holder->flags & (FLAG_PLUS | FLAG_BLANK))
			return (1);
	}
	else if ((holder->type == 'o' || holder->type == 'O')
			&& holder->flags & FLAG_HASH)
		return (0);
	else if (holder->type == 'u' || holder->type == 'U')
		return (0);
	else if ((holder->type == 'x' || holder->type == 'X')
			&& holder->flags & FLAG_HASH)
	{
		if (data_get_inttype(holder) != 0)
			return (2);
	}
	else if (holder->type == 'p')
		return (2);
	return (0);
}

static int	inttype_data_size(t_holder *holder)
{
	size_t	data;
	int		base;
	int		size;

	if (holder->type == 'd' || holder->type == 'i' || holder->type == 'D')
		data = ft_llabs(data_get_inttype(holder));
	else
		data = data_get_inttype(holder);
	if (holder->type == 'o' || holder->type == 'O')
		base = 8;
	else if (holder->type == 'x' || holder->type == 'X' || holder->type == 'p')
		base = 16;
	else
		base = 10;
	size = 0;
	while (data > 0)
	{
		data /= base;
		size += 1;
	}
	if (holder->flags & FLAG_HASH
			&& (holder->type == 'o' || holder->type == 'O'))
		holder->prec = ft_llmax(size + 1, holder->prec);
	return (ft_llmax(size, holder->prec));
}

int			write_inttype(t_holder *holder)
{
	t_buffer	*buffer;
	int			prefix_size;
	int			data_size;

	prefix_size = inttype_prefix_size(holder);
	data_size = inttype_data_size(holder);
	buffer = new_buffer(ft_llmax(holder->width, prefix_size + data_size));
	inttype_prefixpart(holder, prefix_size, data_size, buffer);
	inttype_datapart(holder, prefix_size, data_size, buffer);
	inttype_filling(holder, prefix_size, data_size, buffer);
	return (buffer_print(&buffer));
}
