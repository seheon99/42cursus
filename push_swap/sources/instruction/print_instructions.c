/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:25:38 by seyu              #+#    #+#             */
/*   Updated: 2021/05/24 01:07:59 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"

static int
	print_action(int inst)
{
	if ((inst & ACTION_MASK) == SWAP)
		write(1, "s", 1);
	else if ((inst & ACTION_MASK) == PUSH)
		write(1, "p", 1);
	else if ((inst & ACTION_MASK) == ROTATE)
		write(1, "r", 1);
	else if ((inst & ACTION_MASK) == REVROT)
		write(1, "rr", 2);
	else
		return (FALSE);
	return (TRUE);
}

static int
	print_target(int inst)
{
	if ((inst & TARGET_MASK) == A)
		write(1, "a", 1);
	else if ((inst & TARGET_MASK) == B)
		write(1, "b", 1);
	else if ((inst & TARGET_MASK) == BOTH)
	{
		if ((inst & ACTION_MASK) == PUSH)
			return (FALSE);
		else if ((inst & ACTION_MASK) == REVROT)
			return (print_action(ROTATE));
		else
			return (print_action((inst & ACTION_MASK)));
	}
	return (TRUE);
}

int	print_instruction(int inst)
{
	if (inst > (ACTION_MASK | TARGET_MASK) || inst < 0)
	{
		ft_putnbr_fd(inst, 2);
		return (FALSE);
	}
	if (print_action(inst) == FALSE || print_target(inst) == FALSE)
	{
		ft_putnbr_fd(inst, 2);
		return (FALSE);
	}
	return (TRUE);
}
