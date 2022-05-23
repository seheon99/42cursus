/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_source_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 03:32:25 by seyu              #+#    #+#             */
/*   Updated: 2020/11/07 03:33:59 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx_image.h"
#include "mlx/mlx_window.h"

t_image	*window_find_source(t_window *win, t_image *src)
{
	t_image	*win_src;

	win_src = win->srclst_head;
	while (win_src && win_src != src)
		(win_src) = (win_src)->next_img;
	return (win_src);
}

t_image	*window_find_last_source(t_window *win)
{
	t_image	*srcptr;

	srcptr = win->srclst_head;
	while (srcptr && srcptr->next_img)
		srcptr = srcptr->next_img;
	return (srcptr);
}

t_image	*window_find_prev_source(t_window *win, t_image *src)
{
	t_image	*srcptr;

	srcptr = win->srclst_head;
	if (!srcptr || srcptr == src)
		return (NULL);
	while (srcptr->next_img != src)
		srcptr = srcptr->next_img;
	return (srcptr);
}

int		window_delete_source_all(t_window *win)
{
	while (win->srclst_head)
		window_delete_source(win, win->srclst_head);
	return (0);
}
