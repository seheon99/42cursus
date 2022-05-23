/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_hit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 22:33:06 by seyu              #+#    #+#             */
/*   Updated: 2020/11/06 13:44:11 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing/ray.h"
#include "raytracing/record.h"
#include "raytracing/point3.h"

#include "element/sphere.h"

static double
	discriminant(double a, double half_b, double c)
{
	return (half_b * half_b - a * c);
}

int	sphere_hit(void *sp, const t_ray r, t_range t_minmax, t_hit_record *rec)
{
	t_vec3	oc;
	double	a;
	double	half_b;
	double	c;
	double	t;

	oc = vec3_sub(ray_origin(r), ((t_sphere *)sp)->center);
	a = vec3_length_squared(ray_direction(r));
	half_b = vec3_dot(oc, ray_direction(r));
	c = vec3_length_squared(oc) -
			(((t_sphere *)sp)->radius * ((t_sphere *)sp)->radius);
	if (discriminant(a, half_b, c) < 0)
		return (FALSE);
	t = (-half_b - sqrt(discriminant(a, half_b, c))) / a;
	if (t < t_minmax.min || t > t_minmax.max)
	{
		t = (-half_b + sqrt(discriminant(a, half_b, c))) / a;
		if (t < t_minmax.min || t > t_minmax.max)
			return (FALSE);
	}
	rec->t = t;
	rec->p = ray_at(r, rec->t);
	oc = vec3_div2(vec3_sub(rec->p, ((t_sphere *)sp)->center),
									((t_sphere *)sp)->radius);
	record_set_face_normal(rec, r, oc);
	sphere_get_uv(oc, &(rec->u), &(rec->v));
	rec->mat_ptr = ((t_sphere *)sp)->mat_ptr;
	return (TRUE);
}
