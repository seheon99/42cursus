/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 02:30:23 by seyu              #+#    #+#             */
/*   Updated: 2021/05/19 13:17:29 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structure.h"

void
	s_queue(t_queue *queue)
{
	int	temp[2];

	if (queue->size < 2)
		return ;
	reverse_pop_queue(queue, &temp[0]);
	reverse_pop_queue(queue, &temp[1]);
	push_queue(queue, temp[0]);
	push_queue(queue, temp[1]);
}

void
	p_queue(t_queue *dst, t_queue *src)
{
	int	temp;

	if (src->size < 1)
		return ;
	reverse_pop_queue(src, &temp);
	push_queue(dst, temp);
}

void
	r_queue(t_queue *queue)
{
	int	temp;

	if (queue->size < 2)
		return ;
	reverse_pop_queue(queue, &temp);
	reverse_push_queue(queue, temp);
}

void
	rr_queue(t_queue *queue)
{
	int	temp;

	if (queue->size < 2)
		return ;
	pop_queue(queue, &temp);
	push_queue(queue, temp);
}
