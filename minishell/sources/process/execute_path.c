/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:52:57 by seyu              #+#    #+#             */
/*   Updated: 2021/02/02 02:35:48 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"

static int
	file_exist(const char *path)
{
	t_stat	status;

	if (stat(path, &status) == -1)
		return (FALSE);
	return (TRUE);
}

/*
**	int wait_exit_status(int stat)
**
**	#define _W_INT(w)		(*(int *)&(w))
**	#define _WSTATUS(x)		(_W_INT(x) & 0177)
**
**	#define WEXITSTATUS(x)	((_W_INT(x) >> 8) & 0x000000ff)
**	#define WSTOPSIG(x)		(_W_INT(x) >> 8)
**	#define WIFCONTINUED(x)	(_WSTATUS(x) == _WSTOPPED && WSTOPSIG(x) == 0x13)
**	#define WIFSTOPPED(x)	(_WSTATUS(x) == _WSTOPPED && WSTOPSIG(x) != 0x13)
**	#define WIFEXITED(x)    (_WSTATUS(x) == 0)
**	#define WIFSIGNALED(x)  (_WSTATUS(x) != _WSTOPPED && _WSTATUS(x) != 0)
**	#define WTERMSIG(x)     (_WSTATUS(x))
**
**	#define W_EXITCODE(ret, sig)	((ret) << 8 | (sig))
**	#define W_STOPCODE(sig)			((sig) << 8 | _WSTOPPED)
*/

static int
	execute_file(int *pid, const char *file, char **argv, char **envp)
{
	int	status;

	if ((*pid = fork()) == -1)
		return (print_error(SYSTEM_ERROR, "execute_file", "fork", 1));
	else if (*pid == 0)
	{
		if (execve(file, argv, envp) == -1)
			return (exit_shell(SYSTEM_ERROR, NULL, argv[0], 126));
		return (exit_shell(DEBUG_ERROR, "execute_file", "execve", 1));
	}
	waitpid(*pid, &status, 0);
	if ((status & 0x7f) == 0)
		return ((status >> 8) & 0xff);
	return (*last_status());
}

int	execute_relative_path(t_proc *proc, char **argv, char **envp)
{
	if (file_exist(argv[0]) == TRUE)
		return (execute_file(&(proc->pid), argv[0], argv, envp));
	return (print_error(SYSTEM_ERROR, NULL, argv[0], 1));
}

static char
	*make_command(char *path, char *arg)
{
	char	*str_temp;
	char	*command;

	str_temp = ft_strjoin(path, "/");
	command = ft_strjoin(str_temp, arg);
	free(str_temp);
	return (command);
}

int	execute_absolute_path(t_proc *proc, char **argv, char **envp)
{
	char	**path;
	char	*command;
	int		itr;
	int		exit_code;

	if (!proc || !argv || !envp)
		exit_shell(DEBUG_ERROR, "ececute_absolute_path", "NULL pointer", 1);
	path = ft_split(get_value_ptr("PATH"), ':');
	exit_code = -2;
	itr = -1;
	while (ft_strlen(argv[0]) > 0 && path && path[++itr] && exit_code == -2)
	{
		command = make_command(path[itr], argv[0]);
		if (file_exist(command) == TRUE)
			exit_code = execute_file(&(proc->pid), command, argv, envp);
		free(command);
	}
	if (exit_code == -2)
		exit_code = print_error(ERRNO_INVALID_COMMAND, argv[0], NULL, 127);
	free_string_array(path);
	return (exit_code);
}
