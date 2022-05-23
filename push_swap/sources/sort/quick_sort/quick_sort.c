/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 03:47:01 by seyu              #+#    #+#             */
/*   Updated: 2021/05/24 02:40:09 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static void
	move(t_sort *sort, int data, int pivot[], int no_rotate)
{
	if ((sort->target == A && data < pivot[0]) || \
		(sort->target == B && data > pivot[0]))
	{
		execute_instruction(sort->game, PUSH | (TARGET_MASK - sort->target));
		if ((no_rotate && sort->target == A && data < pivot[1]) || \
			(no_rotate && sort->target == B && data > pivot[1]) || \
			(!no_rotate && sort->target == A && data >= pivot[1]) || \
			(!no_rotate && sort->target == B && data <= pivot[1]))
			execute_instruction(sort->game, \
					ROTATE | (TARGET_MASK - sort->target));
	}
	else
		execute_instruction(sort->game, ROTATE | sort->target);
}

static void
	divide(t_sort *sort, int no_rotate)
{
	t_queue	*target_copy;
	int		pivot[2];
	int		itr;
	int		data;
	int		init_size;

	init_size = sort->game->queue[0]->size - sort->size;
	find_pivot(sort, pivot, pivot + 1, sort->target);
	target_copy = copy_queue(sort->game->queue[sort->target - 1]);
	itr = -1;
	while (++itr < sort->size)
	{
		reverse_pop_queue(target_copy, &data);
		move(sort, data, pivot, no_rotate);
	}
	delete_queue(&target_copy);
	itr = -1;
	while (no_rotate && ++itr < init_size)
		execute_instruction(sort->game, ROTATE | sort->target);
	itr = -1;
	while (!no_rotate && ++itr < (sort->size + 2) / 3)
		execute_instruction(sort->game, REVROT | sort->target);
	itr = -1;
	while (!no_rotate && ++itr < sort->size / 3)
		execute_instruction(sort->game, REVROT | (TARGET_MASK - sort->target));
}

static int
	divide_conqure(t_sort *sort)
{
	t_sort	sort_loop;
	int		itr;
	int		target_itr;

	if (sort->game->queue[1]->size == 0)
		divide(sort, TRUE);
	else
		divide(sort, FALSE);
	sort_loop.game = sort->game;
	sort_loop.size = (sort->size + 2) / 3;
	sort_loop.target = sort->target;
	quick_sort(&sort_loop);
	target_itr = 0;
	while (++target_itr < 3)
	{
		sort_loop.size = (sort->size + target_itr - 1) / 3;
		sort_loop.target = TARGET_MASK - sort->target;
		quick_sort(&sort_loop);
		itr = -1;
		while (++itr < (sort->size + target_itr - 1) / 3)
			execute_instruction(sort->game, PUSH | sort->target);
	}
	return (TRUE);
}

int	quick_sort(t_sort *sort)
{
	t_queue	*target_queue;

	if (sort->target != A && sort->target != B)
		return (FALSE);
	sort->size = number_of_unsorted(sort);
	target_queue = sort->game->queue[sort->target - 1];
	if (is_sorted(target_queue, sort->target, sort->size) == TRUE)
		return (TRUE);
	else if (target_queue->size <= SPECIAL_SIZE)
		return (special_sort(sort));
	else if (sort->size <= SPECIAL_QUICK_SIZE)
		return (special_quick_sort(sort));
	return (divide_conqure(sort));
}
