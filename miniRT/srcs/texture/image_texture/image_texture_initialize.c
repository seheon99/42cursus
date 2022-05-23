/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_texture_initialize.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 17:47:00 by seyu              #+#    #+#             */
/*   Updated: 2020/11/06 17:49:40 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mlx/mlx_color.h"
#include "mlx/mlx_image.h"

#include "texture/texture.h"
#include "texture/image_texture.h"

t_texture	*image_texture_new(t_image *img)
{
	t_texture	*texture;

	texture = (t_texture *)malloc(sizeof(t_texture));
	texture->del = image_texture_delete;
	texture->value = image_texture_value;
	texture->map = (t_image_texture *)malloc(sizeof(t_image_texture));
	((t_image_texture *)(texture->map))->img = img;
	return (texture);
}

void		image_texture_delete(void *map)
{
	free(map);
}
