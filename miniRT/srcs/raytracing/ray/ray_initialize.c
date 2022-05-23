/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_initialize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 04:37:54 by seyu              #+#    #+#             */
/*   Updated: 2020/11/03 03:00:50 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing/ray.h"
#include "libs/vec3.h"

t_ray		ray_create(t_point3 origin, t_vec3 direction)
{
	t_ray	ray;

	ray.orig = origin;
	ray.dir = direction;
	return (ray);
}

t_ray2		ray2_create(t_ray *ray1, t_ray *ray2)
{
	t_ray2	ray;

	ray.ray1 = ray1;
	ray.ray2 = ray2;
	return (ray);
}

t_point3	ray_origin(t_ray ray)
{
	return (ray.orig);
}

t_vec3		ray_direction(t_ray ray)
{
	return (ray.dir);
}
