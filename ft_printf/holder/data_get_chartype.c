/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_get_chartype.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 09:00:54 by seyu              #+#    #+#             */
/*   Updated: 2020/07/16 09:02:01 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "holder.h"

wint_t	data_get_chartype(t_holder *holder)
{
	if (holder->length == LENGTH_L || holder->type == 'C')
		return (*(wint_t *)(holder->data));
	return (*(char *)(holder->data));
}
