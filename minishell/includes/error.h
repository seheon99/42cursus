/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 11:21:51 by seyu              #+#    #+#             */
/*   Updated: 2021/01/25 22:14:59 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define SYSTEM_ERROR			-1
# define DEBUG_ERROR			-2

# define NOERROR				0
# define ERRNO_SYNTAX_QUOTE		1
# define ERRNO_SYNTAX_REDIRECT	2
# define ERRNO_SYNTAX_PIPE		3
# define ERRNO_SYNTAX_SEMICOLON	4
# define ERRNO_SYNTAX_NEWLINE	5
# define ERRNO_INVALID_COMMAND	6
# define ERRNO_INVALID_ID		7
# define ERRNO_NOTSET_OLDPWD	8
# define ERRNO_NOTSET_HOME		9
# define ERRNO_ARGS_TOOMANY		10
# define ERRNO_ARGS_NOTNUM		11

int	*syntax_errno(void);
int	exit_shell(const int err_type,
					const char *command, const char *arg, int return_value);
int	print_error(const int err_type,
					const char *command, const char *arg, int return_value);

#endif
