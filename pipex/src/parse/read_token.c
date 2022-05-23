/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:46:39 by seyu              #+#    #+#             */
/*   Updated: 2021/07/02 16:21:18 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "pipex.h"
#include "pipex_utils.h"

int	read_token(const char *line)
{
	int	read_bytes;
	int	last_bytes;

	read_bytes = 0;
	while (line[read_bytes] == ' ')
		read_bytes++;
	while (read_bytes >= 0 && ft_strchr(" ><|;", line[read_bytes]) == NULL)
	{
		if (line[read_bytes] == '\'' || line[read_bytes] == '"')
			last_bytes = read_quote(line + read_bytes);
		else if (line[read_bytes] == '\\')
			last_bytes = read_escape_char(line + read_bytes);
		else
			last_bytes = read_string(line + read_bytes);
		read_bytes = (last_bytes < 0) ? (-1) : (read_bytes + last_bytes);
	}
	if (read_bytes == -1)
		free(pop_buffer());
	return (read_bytes);
}
