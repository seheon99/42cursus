/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_characters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:47:28 by seyu              #+#    #+#             */
/*   Updated: 2021/07/02 16:20:17 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "pipex_utils.h"

int	read_escape_char(const char *line)
{
	int	read_bytes;

	read_bytes = 0;
	if (line[read_bytes++] != '\\')
		return (perror_int("pipex: input line"));
	if (line[read_bytes] == '\0')
	{
		return (perror_int("pipex: unexcepted EOF"));
	}
	push_buffer(line + read_bytes, 1);
	return (2);
}

int	read_string(const char *line)
{
	int	read_bytes;

	read_bytes = 0;
	while (ft_strchr(" \'\"\\", line[read_bytes]) == NULL)
		read_bytes++;
	push_buffer(line, read_bytes);
	return (read_bytes);
}
