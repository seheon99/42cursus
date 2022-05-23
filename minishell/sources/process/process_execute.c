/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 07:40:03 by seyu              #+#    #+#             */
/*   Updated: 2021/02/01 22:45:03 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int
	change_fd(int fd[2])
{
	static int	std[2];
	static int	is_changed;

	if (is_changed == TRUE && fd == NULL)
	{
		is_changed = FALSE;
		if (dup2(std[0], 0) == -1 || close(std[0]) == -1
				|| dup2(std[1], 1) == -1 || close(std[1]) == -1)
			return (-1);
	}
	else if (is_changed == FALSE && fd != NULL)
	{
		is_changed = TRUE;
		if ((std[0] = dup(0)) == -1
				|| (std[1] = dup(1)) == -1)
			return (-1);
		if ((fd[0] != 0 && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1)))
			return (-1);
		if ((fd[1] != 1 && (dup2(fd[1], 1) == -1 || close(fd[1]) == -1)))
			return (-1);
	}
	else
		exit_shell(DEBUG_ERROR, "change_fd", "abnormal usage", 2);
	return (0);
}

static int
	execute_process(t_proc *proc)
{
	char	**argv;
	char	**envp;

	if (proc->arg_list == NULL)
		return ((*last_status() = 0));
	if (change_fd(proc->fd) == -1)
		return (-1);
	argv = get_argv(proc->arg_list);
	envp = get_envp();
	if (ft_strchr(proc->arg_list->content, '/') != NULL)
		*last_status() = execute_relative_path(proc, argv, envp);
	else if ((*last_status() = execute_builtin(proc, argv)) == -1)
		*last_status() = execute_absolute_path(proc, argv, envp);
	free_string_array(argv);
	free_string_array(envp);
	if (change_fd(NULL) == -1 || *last_status() == -1)
		return (-1);
	return (0);
}

int	execute_process_list(void)
{
	t_list	*proc_list;

	if ((proc_list = *process_list()) == NULL)
		return (*last_status());
	while (proc_list != NULL && *exit_status() == FALSE)
	{
		if (execute_process(proc_list->content) == -1)
			return (-1);
		proc_list = proc_list->next;
	}
	return (*last_status());
}
