/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 11:15:19 by seyu              #+#    #+#             */
/*   Updated: 2021/01/25 00:01:50 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "lib/libft.h"

# include "process.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	1023
# endif

# define REDIRECT_READ		0
# define REDIRECT_WRITE		1
# define REDIRECT_APPEND	2

int		is_buffer_empty(void);
int		push_buffer(const char *src, const int len);
char	*pop_buffer(void);

int		read_quote(const char *line);
int		read_variable(const char *line);
int		read_escape_char(const char *line);
int		read_string(const char *line);

int		read_token(const char *line);

int		parse_redirect(const char *line, int fd[2]);
int		parse_separator(const char *line, t_proc **target_proc_ptr);

int		parse_line(const char *line);

#endif
