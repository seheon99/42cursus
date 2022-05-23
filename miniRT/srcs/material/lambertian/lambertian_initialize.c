/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lambertian_initialize.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 01:10:23 by seyu              #+#    #+#             */
/*   Updated: 2020/11/09 02:18:40 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mlx/mlx_color.h"

#include "material/material.h"
#include "material/lambertian.h"

#include "texture/texture.h"
#include "texture/solid_color.h"

t_material	*lambertian_new(t_texture *a)
{
	t_material	*mat;

	mat = material_new();
	mat->del = lambertian_delete;
	mat->scatter = lambertian_scatter;
	mat->condition = (t_lambertian *)malloc(sizeof(t_lambertian));
	((t_lambertian *)(mat->condition))->albedo = a;
	return (mat);
}

t_material	*lambertian_new_color(t_color c)
{
	return (lambertian_new(solid_color_new(c)));
}

t_material	*lambertian_new_rgb(double r, double g, double b)
{
	return (lambertian_new(solid_color_new_rgb(r, g, b)));
}

void		lambertian_delete(void *condition)
{
	t_texture	*albedo;

	albedo = ((t_lambertian *)condition)->albedo;
	albedo->del(albedo->map);
	((t_lambertian *)condition)->albedo = NULL;
	free(condition);
}
