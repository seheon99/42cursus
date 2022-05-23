/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse_light_scatter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 01:46:47 by seyu              #+#    #+#             */
/*   Updated: 2020/11/09 01:51:11 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx_color.h"

#include "raytracing/record.h"
#include "raytracing/ray.h"

#include "material/material.h"
#include "material/diffuse_light.h"

/*
**	t_ray2	ray
**	*(ray.ray1) = r_in
**	*(ray.ray2) = scattered
*/

int		diffuse_light_scatter(void *light_ptr, t_hit_record rec,
				t_color *attenuation, t_ray2 ray)
{
	light_ptr = 0;
	rec.front_face = 0;
	attenuation = 0;
	ray.ray1 = 0;
	return (0);
}

t_color	diffuse_light_emitted
			(void *light_ptr, double u, double v, t_point3 p)
{
	t_diffuse_light	*light;

	light = light_ptr;
	u = 0;
	v = 0;
	p = point3_create(0, 0, 0);
	return (light->emit->value(light->emit->map, u, v, p));
}
