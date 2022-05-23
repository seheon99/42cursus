/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress_instructions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 06:23:06 by seyu              #+#    #+#             */
/*   Updated: 2021/05/24 01:24:11 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "data_structure.h"
#include "instructions.h"
#include "util.h"
#include "debug.h"

static int
	remove_meaningless_push(t_stack *commit_log[2], int inst)
{
	t_list	*last_a_commit;
	t_list	*last_b_commit;
	int		last_inst;

	if (last_data_stack(commit_log[0], (void **)&last_a_commit) == FALSE || \
		last_data_stack(commit_log[1], (void **)&last_b_commit) == FALSE || \
			last_a_commit != last_b_commit)
		return (FALSE);
	last_inst = *(int *)(last_a_commit->content);
	if ((last_inst | inst) == (PUSH | BOTH))
	{
		ft_lstdelone(last_a_commit, free);
		pop_stack(commit_log[0], NULL);
		pop_stack(commit_log[1], NULL);
		return (TRUE);
	}
	return (FALSE);
}

static int
	remove_instruction(t_stack *commit_log[2], int inst)
{
	t_list	*last_commit;
	int		last_inst;

	if (last_data_stack(commit_log[(inst & TARGET_MASK) - 1], \
			(void **)&last_commit) == FALSE)
		return (FALSE);
	last_inst = *(int *)(last_commit->content);
	if ((last_inst & inst) == SA || (last_inst & inst) == SB || \
			(last_inst == SS && inst == SS) || \
			(last_inst == RA && inst == RRA) || \
			(last_inst == RB && inst == RRB) || \
			(last_inst == RR && inst == RRR) || \
			(last_inst == RRA && inst == RA) || \
			(last_inst == RRB && inst == RB) || \
			(last_inst == RRR && inst == RR))
	{
		ft_lstdelone(last_commit, free);
		pop_stack(commit_log[(inst & TARGET_MASK) - 1], NULL);
		return (TRUE);
	}
	return (FALSE);
}

static int
	combine_instruction(t_stack *commit_log[2], int inst)
{
	t_list	*last_commit;
	int		last_inst;

	if (last_data_stack(commit_log[(inst & TARGET_MASK) - 1], \
			(void **)&last_commit) == FALSE)
		return (FALSE);
	last_commit = last_commit->next;
	while (last_commit != NULL)
	{
		last_inst = *(int *)(last_commit->content);
		if ((last_inst ^ inst) == BOTH)
		{
			*(int *)(last_commit->content) = (inst | BOTH);
			push_stack(commit_log[(inst & TARGET_MASK) - 1], last_commit);
			return (TRUE);
		}
		last_commit = last_commit->next;
	}
	return (FALSE);
}

static int
	push_instruction(t_list **answer_head, t_stack *commit_log[2], int inst)
{
	ft_lstadd_back(answer_head, ft_lstnew(malloc_int(inst)));
	if ((inst & A) || (inst & ACTION_MASK) == PUSH)
		push_stack(commit_log[0], ft_lstlast(*answer_head));
	if ((inst & B) || (inst & ACTION_MASK) == PUSH)
		push_stack(commit_log[1], ft_lstlast(*answer_head));
	return (TRUE);
}

int	compress_instruction(t_queue **answer)
{
	t_list	*answer_head;
	t_stack	*commit_log[2];
	int		new_inst;

	answer_head = NULL;
	commit_log[0] = new_stack();
	commit_log[1] = new_stack();
	while (pop_queue(*answer, &new_inst) == TRUE)
	{
		if (remove_meaningless_push(commit_log, new_inst))
			continue ;
		else if (remove_instruction(commit_log, new_inst) == TRUE)
			continue ;
		else if (combine_instruction(commit_log, new_inst) == TRUE)
			continue ;
		push_instruction(&answer_head, commit_log, new_inst);
	}
	delete_queue(answer);
	delete_stack(commit_log + 0);
	delete_stack(commit_log + 1);
	*answer = list_to_queue(answer_head);
	ft_lstclear(&answer_head, free);
	return (TRUE);
}
