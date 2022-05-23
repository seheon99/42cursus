/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 03:09:06 by seyu              #+#    #+#             */
/*   Updated: 2021/01/22 05:04:12 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void
	prompt_signal(int signo)
{
	ft_putstr_fd("\b\b  \b\b", 1);
	if (signo == SIGINT)
	{
		ft_putstr_fd("\n", 1);
		*last_status() = 1;
		print_prompt();
	}
}

void
	handle_signal_prompt(void)
{
	signal(SIGINT, prompt_signal);
	signal(SIGQUIT, prompt_signal);
}

static void
	exec_signal(int signo)
{
	*last_status() = (1 << 7) + signo;
	if (signo == SIGQUIT)
	{
		ft_putstr_fd("Quit: ", 2);
		ft_putnbr_fd(signo, 2);
	}
	ft_putendl_fd("", 2);
}

void
	handle_signal_exec(void)
{
	signal(SIGINT, exec_signal);
	signal(SIGQUIT, exec_signal);
}
