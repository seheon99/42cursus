/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_operator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 07:46:09 by seyu              #+#    #+#             */
/*   Updated: 2021/05/22 07:42:33 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structure.h"

int	push_queue(t_queue *queue, int data)
{
	int	*new_data;
	int	new_itr;

	if (queue->size == queue->capacity)
	{
		new_data = ft_calloc(queue->capacity * 2, sizeof(int));
		new_itr = 0;
		while (queue->size > 0)
			pop_queue(queue, new_data + new_itr++);
		queue->front = 0;
		queue->rear = queue->capacity;
		queue->size = queue->capacity;
		queue->capacity *= 2;
		free(queue->data);
		queue->data = new_data;
	}
	queue->data[queue->rear] = data;
	queue->size++;
	queue->rear = (queue->rear + 1) % queue->capacity;
	return (queue->size);
}

int	pop_queue(t_queue *queue, int *data)
{
	if (queue->size == 0)
		return (FALSE);
	if (data != NULL)
		*data = queue->data[queue->front];
	queue->data[queue->front] = 0;
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size--;
	return (TRUE);
}

int	reverse_push_queue(t_queue *queue, int data)
{
	int	*new_data;
	int	new_itr;
	int	itr;

	if (queue->size == queue->capacity)
	{
		new_data = ft_calloc(queue->capacity * 2, sizeof(int));
		new_itr = 1;
		itr = queue->front;
		while (new_itr <= queue->size)
		{
			new_data[new_itr++] = queue->data[itr];
			itr = (itr + 1) % queue->capacity;
		}
		queue->front = 1;
		queue->rear = queue->size + 1;
		queue->capacity *= 2;
		free(queue->data);
		queue->data = new_data;
	}
	queue->front = (queue->front + queue->capacity - 1) % queue->capacity;
	queue->data[queue->front] = data;
	queue->size++;
	return (queue->size);
}

int	reverse_pop_queue(t_queue *queue, int *data)
{
	if (queue->size == 0)
		return (FALSE);
	queue->rear = (queue->rear + queue->capacity - 1) % queue->capacity;
	if (data != NULL)
		*data = queue->data[queue->rear];
	queue->data[queue->rear] = 0;
	queue->size--;
	return (TRUE);
}
