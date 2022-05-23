/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inttype_datapart.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 11:38:15 by seyu              #+#    #+#             */
/*   Updated: 2020/10/27 21:27:04 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "holder.h"
#include "buffer.h"
#include "write.h"

#include <stdlib.h>

static int
	ulltostr_get_numsize(unsigned long long int numb, int base)
{
	size_t	rtn;

	rtn = 0;
	while (numb > 0)
	{
		rtn += 1;
		numb /= base;
	}
	return (rtn);
}

static char
	*inttype_ulltostr(unsigned long long int n,
				int prec,
				char *numstr,
				const char *base_str)
{
	int	base;
	int	size;

	if (!base_str || (base = ft_strlen(base_str)) < 2)
		return (0);
	size = ulltostr_get_numsize(n, base);
	prec = ft_llmax(prec - size, 0);
	if (!numstr && !(numstr = malloc(sizeof(char) * (size + 1))))
		return (0);
	numstr[size + prec] = '\0';
	while (size > 0)
	{
		numstr[--size + prec] = base_str[n % base];
		n /= base;
	}
	while (prec > 0)
		numstr[--prec] = base_str[0];
	return (numstr);
}

int	inttype_datapart(t_holder *holder,
			int prefix_size,
			int data_size,
			t_buffer *buf)
{
	int		data_idx;
	ssize_t	data;
	char	*base;

	if (holder->type == 'd' || holder->type == 'i' || holder->type == 'D')
		data = ft_llabs(data_get_inttype(holder));
	else
		data = data_get_inttype(holder);
	data_idx = (holder->flags & FLAG_MINUS
						? prefix_size : buf->size - data_size);
	if (holder->type == 'o' || holder->type == 'O')
		base = "01234567";
	else if (holder->type == 'x' || holder->type == 'p')
		base = "0123456789abcdef";
	else if (holder->type == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789";
	inttype_ulltostr(data, holder->prec, buf->buf + data_idx, base);
	return (data_size);
}
