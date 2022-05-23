/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 23:35:20 by seyu              #+#    #+#             */
/*   Updated: 2021/07/02 16:37:39 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#include "pipex.h"
#include "pipex_utils.h"

static char
	*search_relative_pathname(const char *name)
{
	int	fd;

	if (ft_strchr(name, '/') != NULL)
	{
		if ((fd = open(name, O_RDONLY)) == -1)
			return (perror_ptr(name));
		close(fd);
		if (access(name, X_OK) == -1)
			return (perror_ptr(name));
		return (ft_strdup(name));
	}
	return (NULL);
}

static char
	*get_pathname(const char *path, const char *name)
{
	char	*temp;
	char	*pathname;

	temp = ft_strjoin(path, "/");
	pathname = ft_strjoin(temp, name);
	free(temp);
	return (pathname);
}

static void
	print_error(char *filename)
{
	ft_putstr_fd("pipex: command not found: ", 2);
	ft_putendl_fd(filename, 2);
}

static char
	*check_valid(const char *path, const char *name)
{
	char	*pathname;

	pathname = get_pathname(path, name);
	if (access(pathname, X_OK) == 0)
		return (pathname);
	free(pathname);
	return (NULL);
}

char
	*find_program(char *filename)
{
	char	**paths;
	char	*pathname;
	int		itr;

	if ((pathname = search_relative_pathname(filename)) != NULL)
		return (pathname);
	paths = ft_split(get_path(NULL), ':');
	pathname = NULL;
	itr = -1;
	while (paths[++itr] != NULL)
	{
		if ((pathname = check_valid(paths[itr], filename)) != NULL)
			break ;
	}
	itr = -1;
	while (paths[++itr] != NULL)
		free(paths[itr]);
	free(paths);
	if (pathname == NULL)
		print_error(filename);
	return (pathname);
}
