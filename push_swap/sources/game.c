/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 20:43:49 by seyu              #+#    #+#             */
/*   Updated: 2021/05/22 23:32:57 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

#define INT_MAX 2147483647
#define INT_MIN -2147483648

static int
	is_meaningless_numstr(char *numstr)
{
	if ((numstr[0] == '+' || numstr[0] == '-') && \
			(numstr[1] == '+' || numstr[1] == '-'))
		return (TRUE);
	return (FALSE);
}

static int
	numstr_to_int(int *data_ptr, char *numstr)
{
	long long	data;
	const char	*endptr;

	if (ft_strlen(numstr) == 0 || is_meaningless_numstr(numstr) == TRUE)
		return (FALSE);
	data = ft_strtoll(numstr, &endptr, 10);
	if (*endptr != '\0' || data > INT_MAX || data < INT_MIN)
		return (FALSE);
	*data_ptr = data;
	return (TRUE);
}

static int
	is_duplicated(t_queue *a, int num)
{
	t_queue	*copy;
	int		data;

	copy = copy_queue(a);
	while (pop_queue(copy, &data) == TRUE)
	{
		if (data == num)
		{
			delete_queue(&copy);
			return (TRUE);
		}
	}
	delete_queue(&copy);
	return (FALSE);
}

t_game
	*new_game(char **numstrs)
{
	t_game	*game;
	int		str_itr;
	int		data_itr;
	int		num;

	if (numstrs == NULL || numstrs[0] == NULL)
		return (NULL);
	game = ft_calloc(1, sizeof(t_game));
	game->queue[0] = new_queue();
	game->queue[1] = new_queue();
	game->answer = new_queue();
	str_itr = -1;
	while (numstrs[++str_itr] != NULL)
	{
		if (numstr_to_int(&num, numstrs[str_itr]) == FALSE)
			delete_game(&game);
		data_itr = -1;
		while (game != NULL && ++data_itr < game->queue[0]->size)
			if (is_duplicated(game->queue[0], num) == TRUE)
				delete_game(&game);
		if (game == NULL)
			break ;
		reverse_push_queue(game->queue[0], num);
	}
	return (game);
}

void
	delete_game(t_game **game)
{
	if (game == NULL || *game == NULL)
		return ;
	delete_queue((*game)->queue + 0);
	delete_queue((*game)->queue + 1);
	delete_queue(&((*game)->answer));
	free(*game);
	*game = NULL;
}
