/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 23:53:32 by seyu              #+#    #+#             */
/*   Updated: 2021/02/01 22:49:31 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "minishell.h"

int	*last_status(void)
{
	static int	last_status_;

	return (&last_status_);
}

int	*exit_status(void)
{
	static int	exit_prompt_;

	return (&exit_prompt_);
}

static char
	*get_next_line(void)
{
	char	read_buffer[BUFFER_SIZE + 1];
	int		read_bytes;

	*syntax_errno() = 0;
	free(pop_buffer());
	ft_memset(read_buffer, '\0', BUFFER_SIZE + 1);
	while ((read_bytes = read(STDIN, read_buffer, BUFFER_SIZE)) >= 0)
	{
		if (read_bytes == 0 && is_buffer_empty() == TRUE)
			return (NULL);
		else if (read_bytes > 0 && read_buffer[read_bytes - 1] == '\n')
		{
			push_buffer(read_buffer, read_bytes - 1);
			break ;
		}
		push_buffer(read_buffer, read_bytes);
		if (read_bytes < BUFFER_SIZE)
			write(STDOUT, "  \b\b", 4);
		ft_memset(read_buffer, '\0', read_bytes);
	}
	if (read_bytes < 0)
		exit_shell(SYSTEM_ERROR, "get_next_line", NULL, 0);
	if (is_buffer_empty() == TRUE)
		return (ft_strdup(""));
	return (pop_buffer());
}

static t_list
	*get_next_process_list(void)
{
	char	*line;

	line = NULL;
	while (line == NULL || ft_strlen(line) == 0)
	{
		print_prompt();
		free(line);
		if ((line = get_next_line()) == NULL)
		{
			mini_exit(1, NULL, NOPIPE);
			return (NULL);
		}
	}
	parse_line(line);
	free(line);
	return (*process_list());
}

/*
**	main()
**
**	The main function of Minishell.
**	This function gets the next command line
**		using get_next_process_list() function,
**		splits the command line to command list using ... function,
**		handles the redirections of command list using ... function,
**		and finally, executes the command list sequentially.
**	This function also handles system signals: SIGINT(ctrl+c), SIGQUIT(ctrl+\).
**
**	@param	int		The number of arguments.
**	@param	char*[]	The null terminated array of parameters.
**	@param	char*[]	The null terminated array of
**							"name=value" format environment variables.
**	@return	int		The exit status of last command.
*/

int	main(int argc, const char *argv[], const char *envp[])
{
	argc = 0;
	argv = 0;
	init_variables(envp);
	*exit_status() = FALSE;
	while (*exit_status() == FALSE)
	{
		handle_signal_prompt();
		*process_list() = get_next_process_list();
		if (*process_list() == NULL)
			continue ;
		handle_signal_exec();
		if ((execute_process_list()) == -1)
			*exit_status() = TRUE;
		ft_lstclear(process_list(), free_process);
	}
	return (*last_status());
}
