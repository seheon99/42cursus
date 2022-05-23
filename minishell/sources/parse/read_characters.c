/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_characters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:47:28 by seyu              #+#    #+#             */
/*   Updated: 2021/01/27 00:53:21 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	read_escape_char(const char *line)
{
	int	read_bytes;

	read_bytes = 0;
	if (line[read_bytes++] != '\\')
		return (exit_shell(DEBUG_ERROR, "read_escape_char", line, -1));
	if (line[read_bytes] == '\0')
	{
		*last_status() = 258;
		return (print_error(ERRNO_SYNTAX_NEWLINE, NULL, NULL, -1));
	}
	push_buffer(line + read_bytes, 1);
	return (2);
}

int	read_string(const char *line)
{
	int	read_bytes;

	read_bytes = 0;
	while (ft_strchr(" ><|;$\'\"\\", line[read_bytes]) == NULL)
		read_bytes++;
	push_buffer(line, read_bytes);
	return (read_bytes);
}
