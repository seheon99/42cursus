/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:47:55 by seyu              #+#    #+#             */
/*   Updated: 2021/01/29 19:59:37 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	read_single_quote(const char *line)
{
	int	read_bytes;

	read_bytes = 1;
	while (line[read_bytes] != '\'' && line[read_bytes] != '\0')
		read_bytes++;
	if (line[read_bytes] == '\0')
		return (-1);
	push_buffer(line + 1, read_bytes - 1);
	return (read_bytes + 1);
}

static int
	read_dquote_escape(const char *line)
{
	if (line[1] == '\0')
		return (1);
	else if (line[1] == '\\' || line[1] == '$' || line[1] == '"')
		return (read_escape_char(line));
	else
		return (push_buffer(line, 2));
}

int	read_double_quote(const char *line)
{
	int	read_bytes;
	int	stored_idx;

	read_bytes = 1;
	stored_idx = 1;
	while (line[read_bytes] != '"' && line[read_bytes] != '\0')
	{
		if (line[read_bytes] == '\\' || line[read_bytes] == '$')
		{
			push_buffer(line + stored_idx, read_bytes - stored_idx);
			if (line[read_bytes] == '\\')
				read_bytes += read_dquote_escape(line + read_bytes);
			else if (line[read_bytes] == '$')
				read_bytes += read_variable(line + read_bytes);
			stored_idx = read_bytes;
		}
		else
			read_bytes += 1;
	}
	if (line[read_bytes] == '\0')
		return (-1);
	push_buffer(line + stored_idx, read_bytes - stored_idx);
	return (read_bytes + 1);
}

int	read_quote(const char *line)
{
	int	read_bytes;

	if (line[0] == '\'')
		read_bytes = read_single_quote(line);
	else if (line[0] == '"')
		read_bytes = read_double_quote(line);
	else
		return (exit_shell(DEBUG_ERROR, NULL, NULL, -1));
	if (read_bytes < 0)
	{
		*last_status() = 258;
		return (print_error(ERRNO_SYNTAX_QUOTE, NULL, NULL, -1));
	}
	return (read_bytes);
}
