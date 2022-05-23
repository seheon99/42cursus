/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_initialize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 00:56:25 by seyu              #+#    #+#             */
/*   Updated: 2020/11/06 02:13:28 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "raytracing/camera.h"

#include "utils.h"

t_camera	camera_create(t_point3 lookfrom, t_point3 lookat, t_vec3 vup,
							double vfov, double aspect_ratio,
							double aperture, double focus_dist)
{
	t_camera	cam;
	double		theta;
	double		viewport_height;
	double		viewport_width;

	cam.w = vec3_unit_vector(vec3_sub(lookfrom, lookat));
	cam.u = vec3_unit_vector(vec3_cross(vup, cam.w));
	cam.v = vec3_cross(cam.w, cam.u);

	theta = degrees_to_radians(vfov);
	viewport_height = 2.0 * tan(theta / 2);
	viewport_width = aspect_ratio * viewport_height;
	cam.origin = lookfrom;
	cam.horizontal = vec3_mul2(vec3_mul2(cam.u, viewport_width), focus_dist);
	cam.vertical = vec3_mul2(vec3_mul2(cam.v, viewport_height), focus_dist);
	cam.lower_left_corner =
		vec3_sub(
			vec3_sub(
				vec3_sub(
					cam.origin,
					vec3_div2(cam.horizontal, 2)),
				vec3_div2(cam.vertical, 2)),
			vec3_mul2(cam.w, focus_dist));
	cam.lens_radius = aperture / 2;
	return (cam);
}
