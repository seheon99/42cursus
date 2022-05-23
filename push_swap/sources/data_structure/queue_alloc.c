/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_alloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 19:33:56 by seyu              #+#    #+#             */
/*   Updated: 2021/05/19 13:22:56 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structure.h"

t_queue
	*new_queue(void)
{
	t_queue	*new_queue;

	new_queue = ft_calloc(1, sizeof(t_queue));
	new_queue->capacity = INIT_SIZE;
	new_queue->size = 0;
	new_queue->front = 0;
	new_queue->rear = 0;
	new_queue->data = ft_calloc(INIT_SIZE, sizeof(int));
	return (new_queue);
}

t_queue
	*copy_queue(t_queue *src)
{
	t_queue	*new_queue;
	int		i;

	new_queue = ft_calloc(1, sizeof(t_queue));
	new_queue->capacity = src->capacity;
	new_queue->size = src->size;
	new_queue->front = src->front;
	new_queue->rear = src->rear;
	new_queue->data = ft_calloc(new_queue->capacity, sizeof(int));
	i = -1;
	while (++i < src->capacity)
		new_queue->data[i] = src->data[i];
	return (new_queue);
}

void
	delete_queue(t_queue **queue)
{
	if (queue == NULL || *queue == NULL)
		return ;
	free((*queue)->data);
	free(*queue);
	*queue = NULL;
}
