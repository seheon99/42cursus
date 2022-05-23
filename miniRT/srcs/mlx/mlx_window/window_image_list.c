/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_image_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 03:03:10 by seyu              #+#    #+#             */
/*   Updated: 2020/11/07 03:32:53 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx_image.h"
#include "mlx/mlx_window.h"

t_image	*window_find_image(t_window *win, t_image *img)
{
	t_image	*win_img;

	win_img = win->imglst_head;
	while (win_img && win_img != img)
		(win_img) = (win_img)->next_img;
	return (win_img);
}

t_image	*window_find_last_image(t_window *win)
{
	t_image	*imgptr;

	imgptr = win->imglst_head;
	while (imgptr && imgptr->next_img)
		imgptr = imgptr->next_img;
	return (imgptr);
}

t_image	*window_find_prev_image(t_window *win, t_image *img)
{
	t_image	*imgptr;

	imgptr = win->imglst_head;
	if (!imgptr || imgptr == img)
		return (NULL);
	while (imgptr->next_img != img)
		imgptr = imgptr->next_img;
	return (imgptr);
}

int		window_delete_image_all(t_window *win)
{
	while (win->imglst_head)
		window_delete_image(win, win->imglst_head);
	return (0);
}
