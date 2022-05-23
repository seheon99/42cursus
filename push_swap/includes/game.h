/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 19:08:34 by seyu              #+#    #+#             */
/*   Updated: 2021/05/19 13:17:29 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "data_structure.h"

struct	s_game
{
	t_queue	*queue[2];
	t_queue	*answer;
};
typedef struct s_game	t_game;

t_game	*new_game(char **numstrs);
void	delete_game(t_game **game);

#endif
