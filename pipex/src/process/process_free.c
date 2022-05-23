/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 23:29:17 by seyu              #+#    #+#             */
/*   Updated: 2021/07/02 00:49:21 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "pipex.h"

static void
	free_proc(t_process *proc)
{
	int	itr;

	itr = 0;
	while (proc->argv[itr] != NULL)
		free(proc->argv[itr++]);
	free(proc->argv);
	free(proc->path);
	if (proc->next != NULL)
		free_proc(proc->next);
	free(proc);
}

void
	free_process(t_process **proc)
{
	t_process	*itr;

	itr = *proc;
	while (itr->prev != NULL)
		itr = itr->prev;
	free_proc(itr);
}
