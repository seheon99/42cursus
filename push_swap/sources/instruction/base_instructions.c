/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 21:04:14 by seyu              #+#    #+#             */
/*   Updated: 2021/05/19 13:17:29 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "instructions.h"
#include "data_structure.h"

static int
	swap(t_game *game, int target)
{
	int	done;

	if (target == 0 || target > TARGET_MASK)
		return (FALSE);
	done = FALSE;
	if ((target & A) && game->queue[0]->size >= 2)
	{
		s_queue(game->queue[0]);
		done = TRUE;
	}
	if ((target & B) && game->queue[1]->size >= 2)
	{
		s_queue(game->queue[1]);
		done = TRUE;
	}
	return (done);
}

static int
	push(t_game *game, int target)
{
	int	done;

	if (target == 0 || target == BOTH || target > TARGET_MASK)
		return (FALSE);
	done = FALSE;
	if ((target & A) && game->queue[1]->size >= 1)
	{
		p_queue(game->queue[0], game->queue[1]);
		done = TRUE;
	}
	else if ((target & B) && game->queue[0]->size >= 1)
	{
		p_queue(game->queue[1], game->queue[0]);
		done = TRUE;
	}
	return (done);
}

static int
	rotate(t_game *game, int target)
{
	int	done;

	if (target == 0 || target > TARGET_MASK)
		return (FALSE);
	done = FALSE;
	if ((target & A) && game->queue[0]->size >= 2)
	{
		r_queue(game->queue[0]);
		done = TRUE;
	}
	if ((target & B) && game->queue[1]->size >= 2)
	{
		r_queue(game->queue[1]);
		done = TRUE;
	}
	return (done);
}

static int
	reverse_rotate(t_game *game, int target)
{
	int	done;

	if (target == 0 || target > TARGET_MASK)
		return (FALSE);
	done = FALSE;
	if ((target & A) && game->queue[0]->size >= 2)
	{
		rr_queue(game->queue[0]);
		done = TRUE;
	}
	if ((target & B) && game->queue[1]->size >= 2)
	{
		rr_queue(game->queue[1]);
		done = TRUE;
	}
	return (done);
}

int	execute_instruction(t_game *game, int inst)
{
	int	done;

	if (game == NULL || inst > (ACTION_MASK | TARGET_MASK))
		return (FALSE);
	if ((inst & ACTION_MASK) == SWAP)
		done = swap(game, inst & TARGET_MASK);
	else if ((inst & ACTION_MASK) == PUSH)
		done = push(game, inst & TARGET_MASK);
	else if ((inst & ACTION_MASK) == ROTATE)
		done = rotate(game, inst & TARGET_MASK);
	else if ((inst & ACTION_MASK) == REVROT)
		done = reverse_rotate(game, inst & TARGET_MASK);
	else
		return (FALSE);
	if (done)
		push_queue(game->answer, inst);
	return (done);
}
