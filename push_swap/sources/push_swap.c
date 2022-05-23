/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:00:34 by seyu              #+#    #+#             */
/*   Updated: 2021/05/24 01:03:57 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "instructions.h"
#include "sort.h"

static int
	print_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	*game;
	t_sort	sort;
	int		inst;

	if (argc == 1)
		return (1);
	game = new_game(argv + 1);
	if (game == NULL)
		return (print_error());
	sort.game = game;
	sort.size = game->queue[0]->size;
	sort.target = A;
	quick_sort(&sort);
	efficient_instruction(&(game->answer));
	compress_instruction(&(game->answer));
	efficient_instruction(&(game->answer));
	while (pop_queue(game->answer, &inst))
	{
		if (print_instruction(inst) == FALSE)
			break ;
		write(1, "\n", 1);
	}
	delete_game(&game);
	return (0);
}
