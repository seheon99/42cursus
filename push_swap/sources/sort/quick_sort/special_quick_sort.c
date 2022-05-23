/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_quick_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 04:59:38 by seyu              #+#    #+#             */
/*   Updated: 2021/05/22 07:30:47 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static void
	sort2(t_game *game, int *data, int target)
{
	if ((target == A && data[0] < data[1]) || \
		(target == B && data[0] > data[1]))
		execute_instruction(game, target | SWAP);
}

static void
	sort3(t_game *game, int *data, int target)
{
	if ((target == A && data[1] < data[2]) || \
		(target == B && data[1] > data[2]))
		execute_instruction(game, target | SWAP);
	if ((target == A && (data[0] < data[1] || data[0] < data[2])) || \
		(target == B && (data[0] > data[1] || data[0] > data[2])))
	{
		execute_instruction(game, target | ROTATE);
		execute_instruction(game, target | SWAP);
		execute_instruction(game, target | REVROT);
	}
	if ((target == A && data[0] < data[1] && data[0] < data[2]) || \
		(target == B && data[0] > data[1] && data[0] > data[2]))
		execute_instruction(game, target | SWAP);
}

int	special_quick_sort(t_sort *sort)
{
	t_queue	*target_copy;
	int		*data;
	int		itr;

	if ((sort->target != A && sort->target != B) || \
			sort->game->queue[sort->target - 1]->size < sort->size)
		return (FALSE);
	data = ft_calloc(sort->size, sizeof(int));
	itr = -1;
	target_copy = copy_queue(sort->game->queue[sort->target - 1]);
	while (++itr < sort->size)
		reverse_pop_queue(target_copy, data + sort->size - 1 - itr);
	delete_queue(&target_copy);
	if (sort->size == 2)
		sort2(sort->game, data, sort->target);
	else if (sort->size == 3)
		sort3(sort->game, data, sort->target);
	else
		return (FALSE);
	free(data);
	return (TRUE);
}
