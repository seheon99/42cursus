/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_get_inttype.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 08:53:06 by seyu              #+#    #+#             */
/*   Updated: 2020/07/19 20:04:31 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "holder.h"

ssize_t	inttype_get_signed(t_holder *holder)
{
	if (holder->length == LENGTH_HH)
		return (*(char *)(holder->data));
	else if (holder->length == LENGTH_H)
		return (*(short *)(holder->data));
	else if (holder->length == LENGTH_L || holder->type == 'D')
		return (*(long *)(holder->data));
	else if (holder->length == LENGTH_LL)
		return (*(long long *)(holder->data));
	else
		return (*(int *)(holder->data));
}

size_t	inttype_get_unsigned(t_holder *holder)
{
	if (holder->length == LENGTH_HH)
		return (*(unsigned char *)(holder->data));
	else if (holder->length == LENGTH_H)
		return (*(unsigned short *)(holder->data));
	else if (holder->length == LENGTH_L
			|| holder->type == 'O' || holder->type == 'U')
		return (*(unsigned long *)(holder->data));
	else if (holder->length == LENGTH_LL || holder->type == 'p')
		return (*(unsigned long long *)(holder->data));
	else
		return (*(unsigned int *)(holder->data));
}

size_t	data_get_inttype(t_holder *holder)
{
	if (holder->type == 'd' || holder->type == 'i' || holder->type == 'D')
		return (inttype_get_signed(holder));
	else
		return (inttype_get_unsigned(holder));
}
