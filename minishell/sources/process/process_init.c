/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 11:14:06 by seyu              #+#    #+#             */
/*   Updated: 2021/02/01 21:25:47 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "process.h"

t_proc
	*new_process(int piped)
{
	t_proc	*proc;

	proc = (t_proc *)malloc(sizeof(t_proc));
	proc->arg_list = NULL;
	proc->piped = (piped ? TRUE : FALSE);
	proc->fd[0] = STDIN;
	proc->fd[1] = STDOUT;
	proc->pid = -1;
	return (proc);
}

void
	free_process(void *proc_ptr)
{
	t_proc	*proc;

	proc = proc_ptr;
	ft_lstclear(&(proc->arg_list), free);
	if (proc->fd[0] > 2)
		close(proc->fd[0]);
	if (proc->fd[1] > 2)
		close(proc->fd[1]);
}

t_list
	**process_list(void)
{
	static t_list	*proc_list;

	return (&proc_list);
}
