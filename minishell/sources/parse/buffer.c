/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 19:44:49 by seyu              #+#    #+#             */
/*   Updated: 2021/01/24 03:49:38 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "minishell.h"

static char	*g_buf;
static int	g_buf_size;

static char
	*init_buffer(int added_data_size)
{
	char	*temp;

	if (added_data_size == 0)
		return (g_buf);
	else if (added_data_size < 0)
		return (NULL);
	if (g_buf_size == 0)
	{
		g_buf_size = 32;
		g_buf = ft_calloc(g_buf_size, sizeof(char));
	}
	while (g_buf_size < (int)ft_strlen(g_buf) + added_data_size + 1)
	{
		temp = g_buf;
		g_buf_size *= 2;
		g_buf = ft_calloc(g_buf_size, sizeof(char));
		ft_strlcpy(g_buf, temp, g_buf_size);
		free(temp);
	}
	return (g_buf);
}

int	is_buffer_empty(void)
{
	if (g_buf == NULL && g_buf_size == 0)
		return (TRUE);
	return (FALSE);
}

int	push_buffer(const char *src, int len)
{
	char	*buf;

	if (len < 0)
		return (print_error(DEBUG_ERROR, "push_buffer", NULL, -1));
	else if (len == 0)
		return (len);
	buf = init_buffer(len);
	ft_strncpy(buf + ft_strlen(buf), src, len);
	return (len);
}

char
	*pop_buffer(void)
{
	char	*final_string;

	if (g_buf == NULL)
		return (NULL);
	final_string = ft_strdup(g_buf);
	free(g_buf);
	g_buf = NULL;
	g_buf_size = 0;
	return (final_string);
}
