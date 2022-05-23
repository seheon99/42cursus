/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_variables.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:48:16 by seyu              #+#    #+#             */
/*   Updated: 2021/02/02 10:17:55 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "minishell.h"

static int
	push_last_status_to_buffer(void)
{
	char	*str;

	str = ft_itoa(*last_status());
	push_buffer(str, ft_strlen(str));
	free(str);
	return (2);
}

int	read_variable(const char *line)
{
	char	*name;
	int		read_bytes;

	if (ft_strncmp(line, "$?", 2) == 0)
		return (push_last_status_to_buffer());
	read_bytes = 1;
	if (ft_isalpha(line[read_bytes]) != TRUE && line[read_bytes] != '_')
		return (push_buffer(line, 1));
	while (ft_isalnum(line[++read_bytes]) || line[read_bytes] == '_')
		;
	name = ft_strndup(line + 1, read_bytes - 1);
	if (ft_strlen(name) == 0)
		push_buffer("$", 1);
	else
		push_buffer(get_value_ptr(name), ft_strlen(get_value_ptr(name)));
	free(name);
	return (read_bytes);
}
