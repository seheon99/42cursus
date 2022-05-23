/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   efficient_instructions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 06:23:06 by seyu              #+#    #+#             */
/*   Updated: 2021/05/23 00:03:00 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"

static int
	r_p_rr(t_queue *zipped_answer, int last_inst[3])
{
	if (last_inst[2] == RA && last_inst[1] == PA && last_inst[0] == RRA)
	{
		reverse_pop_queue(zipped_answer, NULL);
		reverse_pop_queue(zipped_answer, NULL);
		push_queue(zipped_answer, PA);
		push_queue(zipped_answer, SA);
		return (TRUE);
	}
	else if (last_inst[2] == RB && last_inst[1] == PB && last_inst[0] == RRB)
	{
		reverse_pop_queue(zipped_answer, NULL);
		reverse_pop_queue(zipped_answer, NULL);
		push_queue(zipped_answer, PB);
		push_queue(zipped_answer, SB);
		return (TRUE);
	}
	return (FALSE);
}

static int
	rr_rrr(t_queue *zipped_answer, int last_inst[3])
{
	if ((last_inst[1] == RRR && last_inst[0] == RR) || \
			(last_inst[1] == RR && last_inst[0] == RRR))
	{
		reverse_pop_queue(zipped_answer, NULL);
		return (TRUE);
	}
	return (FALSE);
}

static int
	reload_instruction(t_queue *zipped, t_queue *answer, int last_inst[3])
{
	int	new_inst;
	int	poped;

	if (pop_queue(answer, &new_inst) == FALSE)
		return (FALSE);
	last_inst[0] = new_inst;
	poped = reverse_pop_queue(zipped, &last_inst[1]);
	if (reverse_pop_queue(zipped, &last_inst[2]) == TRUE)
		push_queue(zipped, last_inst[2]);
	if (poped == TRUE)
		push_queue(zipped, last_inst[1]);
	return (TRUE);
}

int	efficient_instruction(t_queue **answer)
{
	t_queue	*zipped_answer;
	int		*last_inst;

	zipped_answer = new_queue();
	last_inst = ft_calloc(3, sizeof(int));
	while (reload_instruction(zipped_answer, *answer, last_inst) == TRUE)
	{
		if (r_p_rr(zipped_answer, last_inst) == TRUE)
			continue ;
		else if (rr_rrr(zipped_answer, last_inst) == TRUE)
			continue ;
		else
			push_queue(zipped_answer, last_inst[0]);
	}
	delete_queue(answer);
	*answer = zipped_answer;
	free(last_inst);
	return (TRUE);
}
