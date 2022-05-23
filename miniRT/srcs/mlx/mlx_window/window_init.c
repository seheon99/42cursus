/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 03:06:47 by seyu              #+#    #+#             */
/*   Updated: 2020/11/07 03:37:08 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libs/mlx.h"
#include "mlx/mlx_window.h"

t_window	*window_new(int size_x, int size_y, char *title)
{
	t_window	*win;
	int			screen_x;
	int			screen_y;

	win = (t_window *)malloc(sizeof(t_window));
	win->mlx = mlx_init();
	mlx_get_screen_size(win->mlx, &screen_x, &screen_y);
	size_x = size_x < screen_x ? size_x : screen_x;
	size_y = size_y < screen_y ? size_y : screen_y;
	win->mlx_win = mlx_new_window(win->mlx, size_x, size_y, title);
	win->imglst_head = NULL;
	win->current_imgptr = NULL;
	win->srclst_head = NULL;
	return (win);
}

int	window_delete(t_window **win)
{
	int		rtn;

	window_delete_image_all(*win);
	window_delete_source_all(*win);
	rtn = mlx_destroy_window((*win)->mlx, (*win)->mlx_win);
	free(*win);
	*win = NULL;
	exit(0);
	return (rtn);
}

int	window_clear(t_window *win)
{
	return (mlx_clear_window(win->mlx, win->mlx_win));
}
