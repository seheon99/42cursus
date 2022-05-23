/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 01:03:10 by seyu              #+#    #+#             */
/*   Updated: 2020/11/06 02:19:10 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/vec3.h"

#include "raytracing/ray.h"
#include "raytracing/camera.h"

t_ray	camera_get_ray(t_camera cam, double s, double t)
{
	t_ray	ray;
	t_vec3	rd;
	t_vec3	offset;

	rd = vec3_mul2(vec3_random_in_unit_disk(), cam.lens_radius);
	offset = vec3_add(vec3_mul2(cam.u, vec3_x(rd)), vec3_mul2(cam.v, vec3_y(rd)));
	ray = ray_create(vec3_add(cam.origin, offset),
			vec3_sub(vec3_sub(
				vec3_add(
					vec3_add(
						cam.lower_left_corner,
						vec3_mul2(
							cam.horizontal,
							s)),
					vec3_mul2(
						cam.vertical,
						t)),
				cam.origin), offset));
	return (ray);
}
