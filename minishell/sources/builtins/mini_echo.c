/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 10:19:22 by sjaehyeo          #+#    #+#             */
/*   Updated: 2021/02/01 21:54:49 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int
	n_check(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	if (str[i++] == '-')
		n = 1;
	else
		return (FALSE);
	while (str[i])
	{
		if (str[i] != 'n')
			n = 0;
		i++;
	}
	return (n);
}

int	mini_echo(int argc, char **args)
{
	int	i;
	int	n;

	i = 1;
	n = 0;
	if (argc > 1)
	{
		while (args[i] && n_check(args[i]))
		{
			n = 1;
			i++;
		}
		while (args[i])
		{
			ft_putstr_fd(args[i], 1);
			if (args[i + 1] && args[i][0] != '\0')
				write(1, " ", 1);
			i++;
		}
	}
	if (n == 0)
		write(1, "\n", 1);
	return (0);
}
