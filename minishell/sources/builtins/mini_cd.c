/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 16:58:07 by sjaehyeo          #+#    #+#             */
/*   Updated: 2021/01/25 22:11:43 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/errno.h>
#include <stdlib.h>

#include "minishell.h"

static char
	*get_target_path(char *arg)
{
	char	*target_path;

	if (arg == NULL)
	{
		if ((target_path = get_value_ptr("HOME")) == NULL)
		{
			print_error(ERRNO_NOTSET_HOME, "cd", NULL, 0);
			return (NULL);
		}
	}
	else if (ft_strcmp(arg, "-") == 0)
	{
		if ((target_path = get_value_ptr("OLDPWD")) == NULL)
		{
			print_error(ERRNO_NOTSET_OLDPWD, "cd", arg, 0);
			return (NULL);
		}
	}
	else if (ft_strlen(arg) == 0)
		return (".");
	else
		target_path = arg;
	return (target_path);
}

int	mini_cd(int argc, char **argv)
{
	char	*path;
	char	*old_work_directory;

	if (argc == 0 || argv == NULL)
		print_error(DEBUG_ERROR, "cd", NULL, 1);
	if ((old_work_directory = getcwd(NULL, 0)) == NULL)
		return (print_error(SYSTEM_ERROR, "cd", NULL, 1));
	if ((path = get_target_path(argv[1])) == NULL)
		return (1);
	if (chdir(path) != 0)
		return (print_error(SYSTEM_ERROR, "cd", path, 1));
	set_value("OLDPWD", old_work_directory);
	free(old_work_directory);
	path = getcwd(NULL, 0);
	set_value("PWD", path);
	free(path);
	return (0);
}
