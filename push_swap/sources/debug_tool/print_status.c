/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 07:49:25 by seyu              #+#    #+#             */
/*   Updated: 2021/05/22 22:12:13 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"
#include "game.h"

int	print_answer_list(t_list *answer_list, t_stack *commit_log[2])
{
	void	*last_commit[2];

	if (last_data_stack(commit_log[0], &last_commit[0]) == FALSE)
		last_commit[0] = NULL;
	if (last_data_stack(commit_log[1], &last_commit[1]) == FALSE)
		last_commit[1] = NULL;
	while (answer_list != NULL)
	{
		if (answer_list == last_commit[0] || answer_list == last_commit[1])
			write(1, "\033[0;31m", 7);
		print_instruction(*(int *)(answer_list->content));
		if (answer_list == last_commit[0] || answer_list == last_commit[1])
			write(1, "\033[0m", 4);
		answer_list = answer_list->next;
		if (answer_list == NULL)
			write(1, "\n", 1);
		else
			write(1, " ", 1);
	}
	return (TRUE);
}
