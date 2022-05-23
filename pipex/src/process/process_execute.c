/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 23:33:28 by seyu              #+#    #+#             */
/*   Updated: 2021/07/02 15:20:18 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "pipex.h"
#include "pipex_utils.h"

static void
	close_fd(int fd[2])
{
	if (fd[0] != -1)
		close(fd[0]);
	if (fd[1] != -1)
		close(fd[1]);
}

static int
	change_fd(int fd[2])
{
	static int	std[2];
	static int	is_changed;

	if (fd != NULL && (fd[0] == -1 || fd[1] == -1))
		close_fd(fd);
	else if (is_changed == TRUE)
	{
		is_changed = FALSE;
		if (dup2(std[0], 0) == -1 || close(std[0]) == -1
				|| dup2(std[1], 1) == -1 || close(std[1]) == -1)
			return (perror_int("pipex: dup2"));
	}
	else if (is_changed == FALSE && fd != NULL)
	{
		is_changed = TRUE;
		if ((std[0] = dup(0)) == -1
				|| (std[1] = dup(1)) == -1)
			return (perror_int("pipex: dup2"));
		if ((fd[0] != 0 && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1)))
			return (perror_int("pipex: dup2"));
		if ((fd[1] != 1 && (dup2(fd[1], 1) == -1 || close(fd[1]) == -1)))
			return (perror_int("pipex: dup2"));
	}
	return (0);
}

static int
	change_exit(void)
{
	change_fd(NULL);
	exit(1);
	return (0);
}

static t_process
	*rewind_process(t_process *proc)
{
	t_process	*itr;

	itr = proc;
	while (itr->prev != NULL)
		itr = itr->prev;
	return (itr);
}

int	execute_process(t_process *proc, int *pid_array)
{
	t_process	*itr;
	int			pid;
	int			wait_count;

	wait_count = 0;
	itr = rewind_process(proc);
	while (itr != NULL)
	{
		if (itr->fd[0] != -1 && itr->fd[1] != -1)
		{
			change_fd(itr->fd);
			if ((pid = fork()) == -1)
				perror_int("pipex: fork");
			else if (pid == 0)
				if (itr->path != NULL)
					execve(itr->path, itr->argv, get_envp(NULL));
			if (pid <= 0)
				return (change_exit());
			else
				pid_array[wait_count++] = pid;
		}
		change_fd(itr->fd);
		itr = itr->next;
	}
	return (0);
}
