/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 11:12:27 by seyu              #+#    #+#             */
/*   Updated: 2021/02/01 21:32:08 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H

# include <sys/stat.h>

# include "lib/libft.h"

# define NOPIPE		0
# define PIPED		1

# ifndef STDIN
#  define STDIN		0
# endif

# ifndef STDOUT
#  define STDOUT	1
# endif

struct	s_process
{
	t_list	*arg_list;
	t_bool	piped;
	int		fd[2];
	int		pid;
};
typedef	struct s_process	t_proc;
typedef	struct stat			t_stat;

t_proc	*new_process(int piped);
void	free_process(void *proc);
t_list	**process_list(void);

int		execute_builtin(t_proc *proc, char **argv);
int		execute_relative_path(t_proc *proc, char **argv, char **envp);
int		execute_absolute_path(t_proc *proc, char **argv, char **envp);
int		execute_process_list(void);

#endif
