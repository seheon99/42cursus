/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 00:49:43 by seyu              #+#    #+#             */
/*   Updated: 2020/11/06 02:10:56 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "libs/vec3.h"

# include "raytracing/point3.h"
# include "raytracing/ray.h"

struct	s_camera
{
	t_point3	origin;
	t_point3	lower_left_corner;
	t_vec3		horizontal;
	t_vec3		vertical;
	t_vec3		u;
	t_vec3		v;
	t_vec3		w;
	double		lens_radius;
};
typedef	struct s_camera	t_camera;

/*
**	-----------------------------------
**	camera_initialize.c
**	-----------------------------------
*/

t_camera	camera_create(t_point3 lookfrom, t_point3 lookat, t_vec3 vup,
							double vfov, double aspect_ratio,
							double aperture, double focus_dist);

/*
**	-----------------------------------
**	camera_ray.c
**	-----------------------------------
*/

t_ray		camera_get_ray(t_camera cam, double u, double v);

#endif
