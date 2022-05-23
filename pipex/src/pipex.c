/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 21:34:08 by seyu              #+#    #+#             */
/*   Updated: 2021/07/02 02:36:05 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>

#include "pipex.h"
#include "pipex_utils.h"

static void
	set_environment(char **envp)
{
	int	itr;

	get_envp(envp);
	itr = -1;
	while (envp[++itr] != NULL)
	{
		if (ft_strncmp(envp[itr], "PATH", 4) == 0)
		{
			get_path(envp[itr] + 5);
			return ;
		}
	}
	get_path("");
}

int	main(int argc, char **argv, char **envp)
{
	t_process	*proc;
	int			*pid_array;
	int			itr;
	int			statloc;

	if (argc < 5)
		return (print_usage());
	set_environment(envp);
	if ((proc = alloc_process(argc, argv, open(argv[1], O_RDONLY), \
		open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644))) == NULL)
		return (1);
	pid_array = malloc(sizeof(int) * (argc - 3));
	itr = -1;
	while (++itr < argc - 3)
		pid_array[itr] = 0;
	execute_process(proc, pid_array);
	itr = -1;
	while (++itr < argc - 3)
		if (pid_array[itr] != 0)
			waitpid(pid_array[itr], &statloc, 0);
	free(pid_array);
	free_process(&proc);
	return ((statloc >> 8) & 0xff);
}
