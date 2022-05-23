/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 16:22:49 by sjaehyeo          #+#    #+#             */
/*   Updated: 2021/01/25 22:22:14 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "minishell.h"

static int
	is_valid_identifier(char *id)
{
	int	itr;

	itr = -1;
	if (id == NULL || (ft_isalpha(id[++itr]) != TRUE && id[itr] != '_'))
		return (print_error(ERRNO_INVALID_ID, "unset", id, FALSE));
	while (id[++itr] != '\0')
	{
		if (ft_isalnum(id[itr]) != TRUE && id[itr] != '_')
			return (print_error(ERRNO_INVALID_ID, "unset", id, FALSE));
	}
	return (TRUE);
}

int	mini_unset(int argc, char **argv)
{
	int	itr;

	if (argv == NULL || ft_strcmp(argv[0], "unset") != 0)
		return (-DEBUG_ERROR);
	itr = 0;
	while (++itr < argc)
	{
		if (is_valid_identifier(argv[itr]) == TRUE)
			remove_variable(argv[itr]);
	}
	return (0);
}
