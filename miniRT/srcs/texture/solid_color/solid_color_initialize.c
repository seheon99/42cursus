/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solid_color_initialize.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:59:56 by seyu              #+#    #+#             */
/*   Updated: 2020/11/06 16:57:04 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mlx/mlx_color.h"

#include "texture/texture.h"
#include "texture/solid_color.h"

t_texture	*solid_color_new(t_color c)
{
	t_texture	*texture;

	texture = (t_texture *)malloc(sizeof(t_texture));
	texture->del = solid_color_delete;
	texture->value = solid_color_value;
	texture->map = (t_solid_color *)malloc(sizeof(t_solid_color));
	((t_solid_color *)(texture->map))->color_value = c;
	return (texture);
}

t_texture	*solid_color_new_rgb(double red, double green, double blue)
{
	t_color	c;

	c = color_create(red, green, blue);
	return (solid_color_new(c));
}

void		solid_color_delete(void *map)
{
	free(map);
}
