/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 15:49:23 by seyu              #+#    #+#             */
/*   Updated: 2021/05/19 13:23:32 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "data_structure.h"

static void
	append_next_list(t_answer_list **list, int target)
{
	int	empty_answer;
	int	last_inst;

	empty_answer = !last_data_queue((*list)->answer, &last_inst);
	if (empty_answer || (last_inst & ACTION_MASK) != SWAP)
		append_list(list, target | SWAP);
	if (empty_answer || (last_inst & ACTION_MASK) != REVROT)
		append_list(list, target | ROTATE);
	if (empty_answer || (last_inst & ACTION_MASK) != ROTATE)
		append_list(list, target | REVROT);
}

static t_answer_list
	*get_answer_list(t_queue *target_queue, int target)
{
	t_answer_list	*list_head;
	t_answer_list	**list_itr;
	t_answer_list	*answer_list;

	list_head = new_list(copy_queue(target_queue), new_queue());
	if (list_head == NULL)
		return (NULL);
	list_itr = &list_head;
	while (*list_itr != NULL)
	{
		if (is_sorted((*list_itr)->data, target, (*list_itr)->data->size))
			break ;
		append_next_list(list_itr, target);
		list_itr = &((*list_itr)->next);
	}
	answer_list = copy_list(*list_itr);
	answer_list->next = NULL;
	remove_all_list(&list_head);
	return (answer_list);
}

int	special_sort(t_sort *sort)
{
	t_answer_list	*answer_list;
	t_queue			**target_queue;

	if (sort->target == A || sort->target == B)
		target_queue = sort->game->queue + (sort->target - 1);
	else
		return (FALSE);
	answer_list = get_answer_list(*target_queue, sort->target);
	if (answer_list == NULL)
		return (FALSE);
	delete_queue(target_queue);
	*target_queue = copy_queue(answer_list->data);
	append_queue(sort->game->answer, answer_list->answer);
	remove_all_list(&answer_list);
	return (TRUE);
}
