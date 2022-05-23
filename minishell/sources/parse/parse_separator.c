/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_separator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:45:26 by seyu              #+#    #+#             */
/*   Updated: 2021/02/01 22:00:56 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int
	parse_pipe(t_proc **target_proc_ptr)
{
	int	pipe_fd[2];

	if (pipe(pipe_fd) == -1)
	{
		*last_status() = 1;
		return (print_error(SYSTEM_ERROR, "pipe", NULL, -1));
	}
	if ((*target_proc_ptr)->fd[1] == STDOUT)
		(*target_proc_ptr)->fd[1] = pipe_fd[1];
	else
		close(pipe_fd[1]);
	(*target_proc_ptr)->piped = TRUE;
	ft_lstadd_back(process_list(), ft_lstnew(new_process(PIPED)));
	*target_proc_ptr = ft_lstlast(*process_list())->content;
	(*target_proc_ptr)->fd[0] = pipe_fd[0];
	return (0);
}

int	parse_separator(const char *line, t_proc **target_proc_ptr)
{
	int	error_type;

	if (line == NULL || (*line != ';' && *line != '|'))
		return (exit_shell(DEBUG_ERROR, "parse_separator", "line", -1));
	else if ((*target_proc_ptr)->arg_list == NULL)
	{
		error_type = (*line == ';') ?
				ERRNO_SYNTAX_SEMICOLON : ERRNO_SYNTAX_PIPE;
		*last_status() = 258;
		return (print_error(error_type, NULL, NULL, -1));
	}
	if (*line == ';')
	{
		ft_lstadd_back(process_list(), ft_lstnew(new_process(NOPIPE)));
		*target_proc_ptr = ft_lstlast(*process_list())->content;
	}
	else if (*line == '|')
		parse_pipe(target_proc_ptr);
	return (1);
}
