/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 10:58:29 by sjaehyeo          #+#    #+#             */
/*   Updated: 2021/02/01 22:42:17 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool
	is_numberic_string(const char *str)
{
	int	itr;

	itr = 0;
	if (ft_strlen(str) == 0)
		return (FALSE);
	if (str[itr] == '-' || str[itr] == '+')
		itr++;
	while (str[itr] != '\0' && ft_isdigit(str[itr]))
		itr++;
	if (str[itr] == '\0')
		return (TRUE);
	return (FALSE);
}

int	mini_exit(int argc, char **argv, int piped)
{
	if (piped == FALSE)
		ft_putendl_fd("exit", 2);
	if (argc > 2)
		return (print_error(ERRNO_ARGS_TOOMANY, "exit", NULL, 1));
	*exit_status() = TRUE;
	if (argc == 1)
		return (*last_status());
	if (is_numberic_string(argv[1]) == TRUE)
		return (ft_atoi(argv[1]));
	return (print_error(ERRNO_ARGS_NOTNUM, "exit", argv[1], 255));
}
