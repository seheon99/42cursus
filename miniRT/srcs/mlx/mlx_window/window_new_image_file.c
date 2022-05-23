/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_new_image_file.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 01:18:19 by seyu              #+#    #+#             */
/*   Updated: 2020/11/07 03:08:01 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libs/mlx.h"
#include "libs/libft.h"

#include "mlx/mlx_image.h"
#include "mlx/mlx_window.h"

static char
	*get_file_extension(char *filename)
{
	char	*ext_idx;
	int		idx;

	idx = 0;
	while ((ext_idx =
				ft_strnstr(filename + idx + 1, ".", ft_strlen(filename + idx + 1))))
		idx = ext_idx - filename;
	return (filename + idx);
}

static t_image
	*get_last_imgptr(t_window *win)
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
	return (imgptr);
}

static t_image
	*get_image(t_window *win, char *filename, char *extension)
{
	t_image	*imgptr;
	int		*width;
	int		*height;

	imgptr = get_last_imgptr(win);
	width = &(imgptr->width);
	height = &(imgptr->height);
	if (ft_strncmp(extension, ".xpm", ft_strlen(extension)))
		imgptr->mlx_img =
				mlx_xpm_file_to_image(win->mlx, filename, width, height);
	else if (ft_strncmp(extension, ".png", ft_strlen(extension)))
		imgptr->mlx_img =
				mlx_png_file_to_image(win->mlx, filename, width, height);
	if (imgptr->mlx_img == NULL)
	{
		window_delete_image(win, imgptr);
		return (NULL);
	}
	imgptr->addr = mlx_get_data_addr(imgptr->mlx_img,
										&(imgptr->bits_per_pixel),
										&(imgptr->line_length),
										&(imgptr->endian));
	imgptr->next_img = NULL;
	return (imgptr);
}

t_image
	*window_new_image_file(t_window *win, char *filename)
{
	char	*extension;

	extension = get_file_extension(filename);
	return (get_image(win, filename, extension));
}
