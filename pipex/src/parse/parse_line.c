/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 00:41:26 by seyu              #+#    #+#             */
/*   Updated: 2021/07/02 16:24:07 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "pipex.h"
#include "pipex_utils.h"

static char
	**init_argv(void)
{
	char	**argv;

	argv = malloc(sizeof(char *));
	*argv = NULL;
	return (argv);
}

static void
	add_arg(char ***argv, char *arg)
{
	char	**new_argv;
	int		argv_count;
	int		itr;

	argv_count = 0;
	while ((*argv)[argv_count] != NULL)
		argv_count++;
	new_argv = malloc(sizeof(char *) * (argv_count + 2));
	itr = -1;
	while (++itr < argv_count)
		new_argv[itr] = (*argv)[itr];
	new_argv[itr] = arg;
	new_argv[itr + 1] = NULL;
	free(*argv);
	*argv = new_argv;
}

static void
	free_argv(char ***argv)
{
	int	itr;

	itr = 0;
	while ((*argv)[itr] != NULL)
		free((*argv)[itr++]);
	free(*argv);
	*argv = NULL;
}

char
	**parse_line(const char *line)
{
	char	**argv;
	int		last_bytes;

	argv = init_argv();
	last_bytes = 0;
	while (last_bytes >= 0 && *(line += last_bytes) != '\0')
	{
		while (*line == ' ')
			line++;
		if ((last_bytes = read_token(line)) > 0)
			add_arg(&argv,
				(is_buffer_empty() == TRUE ? ft_strdup("") : pop_buffer()));
	}
	if (last_bytes < 0)
		free_argv(&argv);
	return (argv);
}
