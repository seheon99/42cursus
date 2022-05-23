/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:37:45 by seyu              #+#    #+#             */
/*   Updated: 2021/05/19 13:23:32 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structure.h"

int	last_data_queue(t_queue *queue, int *data)
{
	int	last_itr;

	if (queue->size == 0)
		return (FALSE);
	last_itr = (queue->rear + queue->capacity - 1) % queue->capacity;
	*data = queue->data[last_itr];
	return (TRUE);
}

void
	append_queue(t_queue *dst, t_queue *src)
{
	t_queue	*src_copy;
	int		data;

	src_copy = copy_queue(src);
	while (pop_queue(src_copy, &data))
		push_queue(dst, data);
	delete_queue(&src_copy);
}

void
	print_queue(t_queue *q)
{
	int	itr;

	write(1, "Queue:", 6);
	itr = -1;
	while (++itr < q->size)
	{
		write(1, " ", 1);
		ft_putnbr_fd(q->data[(q->front + itr) % q->capacity], 1);
	}
	write(1, "\n", 1);
}

void
	debug_queue(t_queue *q)
{
	write(1, "capacity: ", 11);
	ft_putnbr_fd(q->capacity, 1);
	write(1, "\nsize: ", 7);
	ft_putnbr_fd(q->size, 1);
	write(1, "\nfront: ", 8);
	ft_putnbr_fd(q->front, 1);
	write(1, "\nrear: ", 7);
	ft_putnbr_fd(q->rear, 1);
	write(1, "\nDATA ", 6);
	print_queue(q);
}

t_queue
	*list_to_queue(t_list *list_head)
{
	t_queue	*q;

	q = new_queue();
	while (list_head != NULL)
	{
		push_queue(q, *(int *)(list_head->content));
		list_head = list_head->next;
	}
	return (q);
}
