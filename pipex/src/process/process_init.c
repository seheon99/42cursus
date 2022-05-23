/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 23:04:25 by seyu              #+#    #+#             */
/*   Updated: 2021/07/02 16:24:52 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

#include "pipex.h"
#include "pipex_utils.h"

static t_process
	*new_process(char *argv)
{
	t_process	*proc;

	proc = malloc(sizeof(t_process));
	proc->fd[0] = -1;
	proc->fd[1] = -1;
	proc->argv = parse_line(argv);
	proc->path = find_program(proc->argv[0]);
	proc->prev = NULL;
	proc->next = NULL;
	return (proc);
}

static void
	add_process(t_process **head, t_process *back)
{
	t_process	*itr;

	if (*head == NULL)
	{
		*head = back;
		return ;
	}
	itr = *head;
	while (itr->next != NULL)
		itr = itr->next;
	itr->next = back;
	back->prev = itr;
}

static t_process
	*last_process(t_process *head)
{
	t_process	*itr;

	itr = head;
	while (itr->next != NULL)
		itr = itr->next;
	return (itr);
}

static void
	set_pipes(t_process *head)
{
	t_process	*itr;
	int			fd[2];

	itr = head;
	while (itr->next != NULL)
	{
		pipe(fd);
		itr->fd[1] = fd[1];
		itr->next->fd[0] = fd[0];
		itr = itr->next;
	}
}

t_process
	*alloc_process(int argc, char **argv, int fd_in, int fd_out)
{
	t_process	*proc;
	int			itr;

	if (fd_in == -1)
		perror(argv[1]);
	if (fd_out == -1)
		return (perror_ptr(argv[argc - 1]));
	proc = NULL;
	itr = 1;
	while (argv[++itr + 1] != NULL)
		add_process(&proc, new_process(argv[itr]));
	proc->fd[0] = fd_in;
	set_pipes(proc);
	last_process(proc)->fd[1] = fd_out;
	return (proc);
}
