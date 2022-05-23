/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 22:57:03 by seyu              #+#    #+#             */
/*   Updated: 2021/07/01 22:59:31 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char
	**get_envp(char **main_envp)
{
	static char	**envp;

	if (main_envp != NULL)
		envp = main_envp;
	return (envp);
}

char
	*get_path(char *main_path)
{
	static char	*path;

	if (main_path != NULL)
		path = main_path;
	return (path);
}
