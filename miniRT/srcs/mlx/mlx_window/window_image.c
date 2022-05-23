/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 03:04:46 by seyu              #+#    #+#             */
/*   Updated: 2020/11/07 03:30:52 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "libs/mlx.h"

#include "mlx/mlx_image.h"
#include "mlx/mlx_window.h"

t_image	*window_new_image(t_window *win, int width, int height)
{
	t_image	*imgptr;

	imgptr = window_find_last_image(win);
	if (!imgptr)
	{
		imgptr = (t_image *)malloc(sizeof(t_image));
		win->imglst_head = imgptr;
	}
	else
	{
		imgptr->next_img = (t_image *)malloc(sizeof(t_image));
		imgptr = imgptr->next_img;
	}
	imgptr->mlx_img = mlx_new_image(win->mlx, width, height);
	imgptr->addr = mlx_get_data_addr(imgptr->mlx_img,
										&(imgptr->bits_per_pixel),
										&(imgptr->line_length),
										&(imgptr->endian));
	imgptr->width = width;
	imgptr->height = height;
	imgptr->next_img = NULL;
	return (imgptr);
}

/*
**	window_delete_image
**
**	Connect previous image to next image,
**		and then delete and free img from win
**
**	@param	t_window	*win	win contains img
**	@param	t_image		*img	img will be deleted
**	@return	int			0		img was deleted by the mlx function
**						1		img does not exist in the win pointer
*/

int		window_delete_image(t_window *win, t_image *img)
{
	t_image	*win_img;
	t_image	*prev_img;

	if (!(win_img = window_find_image(win, img)))
		return (1);
	if (!(prev_img = window_find_prev_image(win, img)))
		win->imglst_head = win_img->next_img;
	else
		prev_img->next_img = win_img->next_img;
	if (img->mlx_img)
		mlx_destroy_image(win->mlx, win_img->mlx_img);
	free(win_img);
	return (0);
}

/*
**	window_put_image
**
**	After check if t_image is in t_window,
**		put t_image on t_window.
**
**	@param	t_window	*win	t_window where t_image will be putted
**	@param	t_image		*img	t_image to be putted on t_window
**	@return	int			0		Success to putting t_image on t_window
**						1		There is no t_image in t_window
*/

int		window_put_image(t_window *win, t_image *img, int x, int y)
{
	t_image	*win_img;

	win_img = window_find_image(win, img);
	if (!win_img)
		return (1);
	mlx_put_image_to_window(win->mlx, win->mlx_win, win_img->mlx_img, x, y);
	win->current_imgptr = win_img;
	return (0);
}

int		window_put_next_image(t_window *win)
{
	if (!win)
	{
		perror("Null %s pointer was passed on to the window_put_next_image()");
		exit(1);
	}
	if (win->current_imgptr && win->current_imgptr->next_img)
		win->current_imgptr = win->current_imgptr->next_img;
	else
		win->current_imgptr = win->imglst_head;
	return (window_put_image(win, win->current_imgptr, 0, 0));
}
