/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:53:22 by seyu              #+#    #+#             */
/*   Updated: 2021/01/27 00:47:18 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "minishell.h"

static int
	get_redirection_type(const char *line)
{
	if (line[0] == '<')
		return (REDIRECT_READ);
	else if (line[0] == '>')
		return ((line[1] == '>') ? REDIRECT_APPEND : REDIRECT_WRITE);
	else
		return (exit_shell(DEBUG_ERROR, "get_redirection_type", line, -1));
}

static int
	redirect_file_descriptor(int type, int fd[2])
{
	const char	*file_name;
	int			open_fd;

	file_name = pop_buffer();
	if (type == REDIRECT_READ)
		open_fd = open(file_name, O_RDONLY);
	else if (type == REDIRECT_WRITE)
		open_fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (type == REDIRECT_APPEND)
		open_fd = open(file_name, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		return (exit_shell(DEBUG_ERROR, "redirection_type", NULL, -1));
	if (open_fd == -1)
	{
		*last_status() = 1;
		return (print_error(SYSTEM_ERROR, file_name, NULL, -1));
	}
	fd[(type == REDIRECT_READ) ? 0 : 1] = open_fd;
	return (0);
}

int	parse_redirect(const char *line, int fd[2])
{
	int	type;
	int	read_bytes;
	int	last_bytes;

	read_bytes = 0;
	if ((type = get_redirection_type(line)) == -1)
		return (-1);
	read_bytes += (type == REDIRECT_APPEND) ? 2 : 1;
	if ((last_bytes = read_token(line + read_bytes)) == -1)
		return (-1);
	read_bytes += last_bytes;
	if (is_buffer_empty() == TRUE)
	{
		*last_status() = 258;
		return (print_error(ERRNO_SYNTAX_REDIRECT, NULL, NULL, -1));
	}
	if (redirect_file_descriptor(type, fd) == -1)
		return (-1);
	return (read_bytes);
}
