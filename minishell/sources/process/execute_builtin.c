/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:50:52 by seyu              #+#    #+#             */
/*   Updated: 2021/02/02 00:28:33 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <stdlib.h>

#include "minishell.h"

static int
	call_builtin_func(int argc, char **argv, int piped)
{
	if (ft_strcmp(argv[0], "echo") == 0)
		return (mini_echo(argc, argv));
	else if (ft_strcmp(argv[0], "cd") == 0)
		return (mini_cd(argc, argv));
	else if (ft_strcmp(argv[0], "pwd") == 0)
		return (mini_pwd());
	else if (ft_strcmp(argv[0], "export") == 0)
		return (mini_export(argc, argv));
	else if (ft_strcmp(argv[0], "unset") == 0)
		return (mini_unset(argc, argv));
	else if (ft_strcmp(argv[0], "env") == 0)
		return (mini_env());
	else if (ft_strcmp(argv[0], "exit") == 0)
		return (mini_exit(argc, argv, piped));
	return (-1);
}

static int
	execute_piped_builtin(int argc, char **argv, int piped)
{
	int	pid;
	int	status;

	if ((pid = fork()) == -1)
		return (print_error(SYSTEM_ERROR, "fork", NULL, -1));
	else if (pid == 0)
	{
		*last_status() = call_builtin_func(argc, argv, piped);
		*exit_status() = TRUE;
		return (0);
	}
	else
	{
		waitpid(pid, &status, 0);
		if ((status & 0x7f) == 0)
			return ((status >> 8) & 0xff);
		return (*last_status());
	}
}

static int
	is_builtin_command(char *command)
{
	if (ft_strcmp(command, "echo") == 0)
		return (TRUE);
	else if (ft_strcmp(command, "cd") == 0)
		return (TRUE);
	else if (ft_strcmp(command, "pwd") == 0)
		return (TRUE);
	else if (ft_strcmp(command, "export") == 0)
		return (TRUE);
	else if (ft_strcmp(command, "unset") == 0)
		return (TRUE);
	else if (ft_strcmp(command, "env") == 0)
		return (TRUE);
	else if (ft_strcmp(command, "exit") == 0)
		return (TRUE);
	return (FALSE);
}

int	execute_builtin(t_proc *proc, char **argv)
{
	int	argc;

	argc = -1;
	while (argv != NULL && argv[++argc] != NULL)
		;
	if (argc < 1)
		return (-DEBUG_ERROR);
	else if (is_builtin_command(argv[0]) == FALSE)
		return (-1);
	if (proc->piped == TRUE)
		return (execute_piped_builtin(argc, argv, proc->piped));
	else
		return (call_builtin_func(argc, argv, proc->piped));
}
