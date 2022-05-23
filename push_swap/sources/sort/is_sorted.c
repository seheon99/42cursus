/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 03:01:09 by seyu              #+#    #+#             */
/*   Updated: 2021/05/24 02:29:01 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"
#include "data_structure.h"
#include "sort.h"

int	is_sorted(t_queue *target_queue, int target, int size)
{
	t_queue	*target_copy;
	int		front_data;
	int		rear_data;
	int		itr;
	int		rtn;

	rtn = TRUE;
	target_copy = copy_queue(target_queue);
	reverse_pop_queue(target_copy, &front_data);
	itr = -1;
	while (++itr < size && target_copy->size > 0)
	{
		rear_data = front_data;
		reverse_pop_queue(target_copy, &front_data);
		if ((target == A && front_data < rear_data) || \
				(target == B && front_data > rear_data))
		{
			rtn = FALSE;
			break ;
		}
	}
	delete_queue(&target_copy);
	return (rtn);
}
