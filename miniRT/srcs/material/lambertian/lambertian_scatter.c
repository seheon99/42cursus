/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lambertian_scatter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 01:28:41 by seyu              #+#    #+#             */
/*   Updated: 2020/11/06 17:23:58 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx_color.h"

#include "raytracing/record.h"
#include "raytracing/ray.h"

#include "material/material.h"
#include "material/lambertian.h"

/*
**	t_ray2	ray
**	*(ray.ray1) = r_in
**	*(ray.ray2) = scattered
*/

int	lambertian_scatter(void *lamb, t_hit_record rec,
				t_color *attenuation, t_ray2 ray)
{
	t_lambertian	*lambertian;
	t_vec3			scatter_direction;
	t_ray			*r_in;
	t_ray			*scattered;

	lambertian = lamb;
	r_in = ray.ray1;
	scattered = ray.ray2;
	scatter_direction = vec3_add(rec.normal, vec3_random_unit_vector());
	if (vec3_is_near_zero(scatter_direction))
		scatter_direction = rec.normal;
	*scattered = ray_create(rec.p, scatter_direction);
	*attenuation = lambertian->albedo->value(
								lambertian->albedo->map, rec.u, rec.v, rec.p);
	return (1);
}
