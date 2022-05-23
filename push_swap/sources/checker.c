/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 13:50:08 by seyu              #+#    #+#             */
/*   Updated: 2021/05/17 02:41:24 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "libft.h"
#include "get_next_line.h"

#include "instructions.h"
#include "game.h"
#include "sort.h"

static int
	str_to_instruction(const char *string)
{
	int	action;
	int	target;

	if (ft_strlen(string) == 2 && string[0] == 's')
		action = SWAP;
	else if (ft_strlen(string) == 2 && string[0] == 'p')
		action = PUSH;
	else if (ft_strlen(string) == 2 && string[0] == 'r')
		action = ROTATE;
	else if (ft_strlen(string) == 3 && ft_strncmp(string, "rr", 2) == 0)
		action = REVROT;
	else
		return (FALSE);
	if ((action == REVROT && string[2] == 'a') || string[1] == 'a')
		target = A;
	else if ((action == REVROT && string[2] == 'b') || string[1] == 'b')
		target = B;
	else if ((action == SWAP && (string[1]) == 's') || \
			(action == ROTATE && (string[1]) == 'r') || \
			(action == REVROT && (string[2]) == 'r'))
		target = BOTH;
	else
		return (FALSE);
	return (action | target);
}

static int
	start_game(t_game *game)
{
	char	*line;
	int		input_status;
	int		inst;

	input_status = 1;
	while (input_status > 0)
	{
		input_status = get_next_line(0, &line);
		if (input_status >= 0 && ft_strlen(line) > 0)
		{
			inst = str_to_instruction(line);
			if (inst == FALSE)
				input_status = -1;
			else
				execute_instruction(game, inst);
		}
		free(line);
		if (input_status < 0)
			return (FALSE);
	}
	return (TRUE);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc == 1)
		return (1);
	game = new_game(argv + 1);
	if (game == NULL || start_game(game) == FALSE)
		write(2, "Error\n", 6);
	else if (game->queue[1]->size == 0 && \
			is_sorted(game->queue[0], A, game->queue[0]->size) == TRUE)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	delete_game(&game);
	return (0);
}
