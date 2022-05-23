/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_texture_value.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 17:50:08 by seyu              #+#    #+#             */
/*   Updated: 2020/11/07 15:02:57 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>

#include "mlx/mlx_color.h"
#include "mlx/mlx_image.h"

#include "texture/texture.h"
#include "texture/image_texture.h"

#include "utils.h"

t_color	image_texture_value(void *map, double u, double v, t_vec3 p)
{
	t_image_texture	*img_texture;
	int				i;
	int				j;

	p = vec3_create_empty();
	img_texture = map;
	if (img_texture->img == NULL)
		return (color_create(0, 1, 1));
	i = clamp(u, 0, 1) * img_texture->img->width;
	j = clamp(v, 0, 1) * img_texture->img->height;
	if (i >= img_texture->img->width)
		i = img_texture->img->width - 1;
	if (j >= img_texture->img->height)
		j = img_texture->img->height - 1;
	return (image_pixel_get_color(img_texture->img, i, j));
}
