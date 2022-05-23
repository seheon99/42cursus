/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 04:32:02 by seyu              #+#    #+#             */
/*   Updated: 2020/11/05 19:05:00 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "libs/vec3.h"
# include "raytracing/point3.h"

# define MAX_DEPTH 50

struct		s_ray
{
	t_point3	orig;
	t_vec3		dir;
};
typedef	struct s_ray	t_ray;

struct		s_range
{
	double	min;
	double	max;
};
typedef	struct s_range	t_range;

struct		s_ray2
{
	t_ray	*ray1;
	t_ray	*ray2;
};
typedef	struct s_ray2	t_ray2;

/*
**	-----------------------------------
**	ray_initialize.c
**	-----------------------------------
*/

t_ray		ray_create(t_point3 origin, t_vec3 direction);
t_ray2		ray2_create(t_ray *ray1, t_ray *ray2);
t_point3	ray_origin(t_ray ray);
t_vec3		ray_direction(t_ray ray);

/*
**	-----------------------------------
**	ray_utils.c
**	-----------------------------------
*/

t_point3	ray_at(t_ray ray, double t);

/*
**	-----------------------------------
**	range_initialize.c
**	-----------------------------------
*/

t_range		range_create(double min, double max);

#endif
