/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 21:34:13 by seyu              #+#    #+#             */
/*   Updated: 2021/07/02 16:20:02 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stddef.h>

# define TRUE 1
# define FALSE 0

struct		s_process
{
	int					fd[2];
	int					pid;
	char				*path;
	char				**argv;
	struct s_process	*prev;
	struct s_process	*next;
};
typedef struct s_process	t_process;

int			is_buffer_empty(void);
int			push_buffer(const char *src, int len);
char		*pop_buffer(void);
char		**parse_line(const char *line);
int			read_escape_char(const char *line);
int			read_string(const char *line);
int			read_single_quote(const char *line);
int			read_double_quote(const char *line);
int			read_quote(const char *line);
int			read_token(const char *line);

char		*set_process(const char *filename);

t_process	*alloc_process(int argc, char **argv, int fd_in, int fd_out);
void		free_process(t_process **proc);
int			execute_process(t_process *proc, int *pid_array);

char		*find_program(char *filename);

char		**get_envp(char **main_envp);
char		*get_path(char *main_path);

int			perror_int(const char *str);
void		*perror_ptr(const char *str);
int			print_usage();

#endif
