/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 21:27:33 by seyu              #+#    #+#             */
/*   Updated: 2020/11/06 16:48:14 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# define TRUE 1
# define FALSE 0

# include "raytracing/ray.h"
# include "raytracing/point3.h"
# include "raytracing/record.h"

# include "element/hittable.h"

# include "material/material.h"

struct	s_sphere
{
	t_point3	center;
	double		radius;
	t_material	*mat_ptr;
};
typedef	struct s_sphere	t_sphere;

/*
**	-----------------------------------
**	sphere_initialize.c
**	-----------------------------------
*/

t_hittable
		*sphere_new(t_point3 center, double radius, t_material *mat_ptr);
void	sphere_delete(void *hittable);

/*
**	-----------------------------------
**	sphere_hit.c
**	-----------------------------------
*/

int		sphere_hit(
			void *sp, const t_ray r, t_range t_minmax, t_hit_record *rec);

/*
**	-----------------------------------
**	sphere_get_uv.c
**	-----------------------------------
*/

void	sphere_get_uv(const t_point3 p, double *u, double *v);

#endif
