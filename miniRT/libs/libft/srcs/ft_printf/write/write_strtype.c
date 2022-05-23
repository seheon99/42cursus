/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_strtype.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 16:29:54 by seyu              #+#    #+#             */
/*   Updated: 2020/10/27 21:28:01 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>

#include "libft.h"
#include "buffer.h"
#include "holder.h"
#include "write.h"
#include "utils.h"

static int	data_size_s(t_holder *holder)
{
	int	data_len;

	data_len = ft_strlen(*(char **)(holder->data));
	if (holder->prec == -2)
		return (data_len);
	return (ft_llmin(data_len, holder->prec));
}

static int	data_size_ls(t_holder *holder)
{
	wchar_t	ch;
	int		data_size;
	int		ch_size;
	int		itr;

	data_size = 0;
	ch_size = 0;
	itr = 0;
	while ((data_size + ch_size <= holder->prec || holder->prec == -2)
			&& (*(wchar_t **)(holder->data))[itr == 0 ? 0 : itr - 1])
	{
		data_size += ch_size;
		ch = ((*(wchar_t **)(holder->data)))[itr++];
		if ((ch_size = pf_convert_unicode_to_utf8(ch, NULL)) == 0)
			return (-1);
	}
	return (data_size);
}

static int	strtype_data_size(t_holder *holder)
{
	if (holder->length == LENGTH_L || holder->type == 'S')
		return (data_size_ls(holder));
	return (data_size_s(holder));
}

int			write_strtype(t_holder *holder)
{
	t_buffer	*buffer;
	int			data_size;

	if ((data_size = strtype_data_size(holder)) == -1)
		return (-1);
	buffer = new_buffer(ft_llmax(holder->width, data_size));
	strtype_datapart(holder, data_size, buffer);
	strtype_filling(holder, data_size, buffer);
	return (buffer_print(&buffer));
}
