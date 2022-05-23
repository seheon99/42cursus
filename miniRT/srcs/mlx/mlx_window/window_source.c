/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_source.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 02:53:18 by seyu              #+#    #+#             */
/*   Updated: 2020/11/07 03:35:27 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>

#include "libs/mlx.h"
#include "libs/libft.h"

#include "mlx/mlx_image.h"
#include "mlx/mlx_window.h"

static char
	*get_ext(char *filename)
{
	char	*ext_idx;
	int		idx;

	idx = 0;
	while ((ext_idx = ft_strnstr(filename + idx + 1,
									".", ft_strlen(filename + idx + 1))))
		idx = ext_idx - filename;
	return (filename + idx);
}

static int
	is_valid(char *filename)
{
	char	*ext;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	ext = get_ext(filename);
	if (ft_strncmp(ext, ".xpm", ft_strlen(ext)) &&
			ft_strncmp(ext, ".png", ft_strlen(ext)))
		return (0);
	return (1);
}

static void
	set_imgptr_width_height(t_window *win, t_image *img, char *filename)
{
	char	*ext;

	ext = get_ext(filename);
	if (!ft_strncmp(ext, ".xpm", ft_strlen(ext)))
		img->mlx_img = mlx_xpm_file_to_image(
						win->mlx, filename, &(img->width), &(img->height));
	else if (!ft_strncmp(ext, ".png", ft_strlen(ext)))
		img->mlx_img = mlx_png_file_to_image(
						win->mlx, filename, &(img->width), &(img->height));
}

t_image	*window_new_source(t_window *win, char *filename)
{
	t_image	*srcptr;

	if (!is_valid(filename))
		return (NULL);
	srcptr = window_find_last_source(win);
	if (!srcptr)
	{
		srcptr = (t_image *)malloc(sizeof(t_image));
		win->srclst_head = srcptr;
	}
	else
	{
		srcptr->next_img = (t_image *)malloc(sizeof(t_image));
		srcptr = srcptr->next_img;
	}
	set_imgptr_width_height(win, srcptr, filename);
	srcptr->addr = mlx_get_data_addr(srcptr->mlx_img,
										&(srcptr->bits_per_pixel),
										&(srcptr->line_length),
										&(srcptr->endian));
	srcptr->next_img = NULL;
	return (srcptr);
}

int		window_delete_source(t_window *win, t_image *src)
{
	t_image	*win_src;
	t_image	*prev_src;

	if (!(win_src = window_find_source(win, src)))
		return (1);
	if (!(prev_src = window_find_prev_source(win, src)))
		win->srclst_head = win_src->next_img;
	else
		prev_src->next_img = win_src->next_img;
	if (src->mlx_img)
		mlx_destroy_image(win->mlx, win_src->mlx_img);
	free(win_src);
	return (0);
}
