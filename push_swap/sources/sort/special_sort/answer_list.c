/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   answer_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:47:56 by seyu              #+#    #+#             */
/*   Updated: 2021/05/19 13:17:29 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "data_structure.h"

t_answer_list
	*new_list(t_queue *data, t_queue *answer)
{
	t_answer_list	*list;

	list = ft_calloc(1, sizeof(t_answer_list));
	if (list == NULL)
		return (NULL);
	list->answer = answer;
	list->data = data;
	list->next = NULL;
	return (list);
}

t_answer_list
	*copy_list(t_answer_list *list)
{
	t_answer_list	*new_list;

	new_list = ft_calloc(1, sizeof(t_answer_list));
	new_list->answer = copy_queue(list->answer);
	new_list->data = copy_queue(list->data);
	new_list->next = list->next;
	return (new_list);
}

void
	remove_all_list(t_answer_list **head)
{
	t_answer_list	*list;

	list = *head;
	while (list != NULL)
	{
		delete_queue(&(list->data));
		delete_queue(&(list->answer));
		*head = list->next;
		free(list);
		list = *head;
	}
}

void
	append_list(t_answer_list **list, int inst)
{
	t_queue	*data;
	t_queue	*answer;

	data = copy_queue((*list)->data);
	answer = copy_queue((*list)->answer);
	if ((inst & ACTION_MASK) == SWAP)
		s_queue(data);
	else if ((inst & ACTION_MASK) == ROTATE)
		r_queue(data);
	else if ((inst & ACTION_MASK) == REVROT)
		rr_queue(data);
	push_queue(answer, inst);
	while (*list != NULL)
		list = &((*list)->next);
	*list = new_list(data, answer);
}
