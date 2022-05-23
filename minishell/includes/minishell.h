/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 23:45:28 by seyu              #+#    #+#             */
/*   Updated: 2021/01/29 20:04:29 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "lib/libft.h"

# include "util/print.h"
# include "util/string_array.h"

# include "builtin.h"
# include "error.h"
# include "parse.h"
# include "process.h"
# include "signal.h"
# include "variable.h"

# ifndef STDIN
#  define STDIN 0
# endif

# ifndef STDOUT
#  define STDOUT 1
# endif

# ifndef STDERR
#  define STDERR 2
# endif

/*
**	Escaped Color String
*/

# define NOCOLOR		"\033[0m"
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define ORANGE			"\033[33m"
# define BLUE			"\033[34m"
# define PURPLE			"\033[35m"
# define CYAN			"\033[36m"
# define LIGHTGRAY		"\033[37m"
# define DARKGRAY		"\033[90m"
# define LIGHTRED		"\033[91m"
# define LIGHTGREEN		"\033[92m"
# define YELLOW			"\033[93m"
# define LIGHTBLUE		"\033[94m"
# define LIGHTPURPLE	"\033[95m"
# define LIGHTCYAN		"\033[96m"
# define WHITE			"\033[97m"

int	*last_status(void);
int	*exit_status(void);

#endif
