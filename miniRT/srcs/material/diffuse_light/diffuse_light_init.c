/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse_light_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 01:42:17 by seyu              #+#    #+#             */
/*   Updated: 2020/11/09 02:18:58 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "material/diffuse_light.h"

#include "texture/texture.h"
#include "texture/solid_color.h"

t_material	*diffuse_light_new(t_texture *a)
{
	t_material	*mat;

	mat = material_new();
	mat->del = diffuse_light_delete;
	mat->scatter = diffuse_light_scatter;
	mat->emitted = diffuse_light_emitted;
	mat->condition = (t_diffuse_light *)malloc(sizeof(t_diffuse_light));
	((t_diffuse_light *)(mat->condition))->emit = a;
	return (mat);
}

t_material	*diffuse_light_new_color(t_color c)
{
	return (diffuse_light_new(solid_color_new(c)));
}

t_material	*diffuse_light_new_rgb(double r, double g, double b)
{
	return (diffuse_light_new(solid_color_new_rgb(r, g, b)));
}

void		diffuse_light_delete(void *condition)
{
	t_texture	*emit;

	emit = ((t_diffuse_light *)condition)->emit;
	emit->del(emit->map);
	((t_diffuse_light *)condition)->emit = NULL;
	free(condition);
}
