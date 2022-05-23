/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 21:28:56 by seyu              #+#    #+#             */
/*   Updated: 2021/02/01 22:38:34 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/errno.h>
#include <string.h>

#include "minishell.h"

static char	*g_syntax_error_string[] = {
	"No error has occurred",
	"syntax error near unexpected quote token",
	"syntax error near unexpected redirection token",
	"syntax error near unexpected pipe token",
	"syntax error near unexpected semicolon token",
	"syntax error near unexpected newline token",
	"command not found",
	"not a valid identifier",
	"OLDPWD not set",
	"HOME not set",
	"too many arguments",
	"numeric argument required"
};

int	*syntax_errno(void)
{
	static int	syntax_error_number;

	return (&syntax_error_number);
}

int	exit_shell(const int err_code,
					const char *command, const char *arg, int return_value)
{
	*exit_status() = TRUE;
	return (print_error(err_code, command, arg, return_value));
}

int	print_error(const int err_code,
					const char *command, const char *arg, int return_value)
{
	ft_putstr_fd("minishell: ", 2);
	if (command)
	{
		ft_putstr_fd((char *)command, 2);
		ft_putstr_fd(": ", 2);
	}
	if (arg)
	{
		ft_putstr_fd((char *)arg, 2);
		ft_putstr_fd(": ", 2);
	}
	if (err_code == SYSTEM_ERROR || err_code == DEBUG_ERROR)
		ft_putendl_fd(strerror(errno), 2);
	else
	{
		*syntax_errno() = err_code;
		ft_putendl_fd(g_syntax_error_string[err_code], 2);
	}
	if (err_code == DEBUG_ERROR)
		ft_putendl_fd("(Need debugging)", 2);
	return (return_value);
}
