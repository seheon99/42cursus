/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlelectric_scatter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:46:21 by seyu              #+#    #+#             */
/*   Updated: 2020/11/05 23:22:07 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "libs/vec3.h"

#include "mlx/mlx_color.h"

#include "raytracing/record.h"
#include "raytracing/ray.h"

#include "material/material.h"
#include "material/dielectric.h"

#include "utils.h"

/*
**	t_ray2	ray
**	*(ray.ray1) = r_in
**	*(ray.ray2) = scattered
*/

int	dielectric_scatter(void *dielectric, t_hit_record rec,
					t_color *attenuation, t_ray2 ray)
{
	double			refraction_ratio;
	t_vec3			unit_direction;
	t_vec3			direction;
	double			cos_theta;
	double			sin_theta;

	*attenuation = color_create(1.0, 1.0, 1.0);
	refraction_ratio = (rec.front_face ?
								(1.0 / ((t_dielectric *)(dielectric))->ir)
								: ((t_dielectric *)(dielectric))->ir);
	unit_direction = vec3_unit_vector(ray_direction(*(ray.ray1)));
	cos_theta = fmin(vec3_dot(vec3_minus(unit_direction), rec.normal), 1.0);
	sin_theta = sqrt(1.0 - cos_theta * cos_theta);
	if (refraction_ratio * sin_theta > 1.0
			|| dielectric_reflactance(cos_theta, refraction_ratio)
					> random_double(0, 1))
		direction = vec3_reflect(unit_direction, rec.normal);
	else
		direction = vec3_refract(unit_direction, rec.normal, refraction_ratio);
	*(ray.ray2) = ray_create(rec.p, direction);
	return (1);
}
