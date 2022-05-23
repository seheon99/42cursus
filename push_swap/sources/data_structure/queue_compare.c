/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_compare.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 16:08:27 by seyu              #+#    #+#             */
/*   Updated: 2021/05/19 13:17:29 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structure.h"

int	is_equal_queue(t_queue *q0, t_queue *q1)
{
	t_queue	*copy[2];
	int		data[2];
	int		rtn;

	if (q0->size != q1->size)
		return (FALSE);
	copy[0] = copy_queue(q0);
	copy[1] = copy_queue(q1);
	rtn = TRUE;
	while (copy[0]->size > 0)
	{
		pop_queue(copy[0], data);
		pop_queue(copy[1], data + 1);
		if (data[0] != data[1])
		{
			rtn = FALSE;
			break ;
		}
	}
	delete_queue(copy);
	delete_queue(copy + 1);
	return (rtn);
}
