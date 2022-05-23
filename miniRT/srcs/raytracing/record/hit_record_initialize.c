/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_record_initialize.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 23:44:10 by seyu              #+#    #+#             */
/*   Updated: 2020/11/06 05:01:59 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/vec3.h"
#include "raytracing/ray.h"
#include "raytracing/record.h"

void	record_copy(t_hit_record *dst, t_hit_record src)
{
	dst->p = src.p;
	dst->normal = src.normal;
	dst->mat_ptr = src.mat_ptr;
	dst->t = src.t;
	dst->u = src.u;
	dst->v = src.v;
	dst->front_face = src.front_face;
}

void	record_set_face_normal(
	t_hit_record *record,
	const t_ray r,
	const t_vec3 outward_normal
)
{
	record->front_face = (vec3_dot(ray_direction(r), outward_normal) < 0);
	record->normal =
			record->front_face ? outward_normal : vec3_minus(outward_normal);
}
