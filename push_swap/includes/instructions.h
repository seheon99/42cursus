/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 20:37:45 by seyu              #+#    #+#             */
/*   Updated: 2021/05/22 22:25:35 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H

# include "libft.h"
# include "game.h"

# define TARGET_MASK	3
# define A		1
# define B		2
# define BOTH	3

# define ACTION_MASK	60
# define SWAP	4
# define PUSH	8
# define ROTATE	16
# define REVROT	32

/*
**	Action Bits
**	0000 -> swap
**	0001 -> push
**	0100 -> rotate
**	1000 -> reverse rotate
**
**	Target Bits
**	01 -> A
**	10 -> B
**	11 -> A and B (Both)
**
**	How to represent the instructions in bits
**	((action bits) << 2) | (target bits)
**
**	ex)
**	sa = SWAP | A
**	ss = SWAP | BOTH
**	rra = REVROT | A
**	(SWAP | A) & ACTION_MASK == SWAP (true)
**	(SWAP | A) & ACTION_MASK == REVROT (false)
**	(REVROT | A) & ACTION_MASK == REVROT (true)
**	(SWAP | A) & TARGET_MASK == A (true)
**	(SWAP | A) & TARGET_MASK == BOTH (false)
**	(SWAP | BOTH) & TARGET_MASK == B (true)
**	(SWAP | BOTH) & TARGET_MASK == BOTH (true)
*/

# define SA		5
# define SB 	6
# define SS 	7
# define PA 	9
# define PB 	10
# define RA 	17
# define RB 	18
# define RR 	19
# define RRA 	33
# define RRB 	34
# define RRR 	35

int	execute_instruction(t_game *game, int inst);
int	compress_instruction(t_queue **answer);
int	efficient_instruction(t_queue **answer);
int	print_instruction(int inst);

#endif
