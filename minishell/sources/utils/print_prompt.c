/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 21:11:54 by seyu              #+#    #+#             */
/*   Updated: 2021/01/01 12:48:08 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void
	print_prompt(void)
{
	int	status;

	status = *last_status();
	if (status == 0)
	{
		ft_putstr_fd(BLUE, 1);
		ft_putstr_fd("minishell$ ", 1);
		ft_putstr_fd(NOCOLOR, 1);
	}
	else
	{
		ft_putstr_fd(RED, 1);
		ft_putnbr_fd(status, 1);
		ft_putstr_fd(" minishell$ ", 1);
		ft_putstr_fd(NOCOLOR, 1);
	}
}
