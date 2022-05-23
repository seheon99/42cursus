/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:19:49 by seyu              #+#    #+#             */
/*   Updated: 2020/11/05 19:05:05 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "vec3.h"

t_vec3	vec3_reflect(const t_vec3 v, const t_vec3 n)
{
	return (vec3_sub(v, vec3_mul2(
				vec3_mul2(n, vec3_dot(v, n)), 2)));
}

t_vec3	vec3_refract(const t_vec3 uv, const t_vec3 n, double etai_over_etat)
{
	double	cos_theta;
	t_vec3	r_out_perp;
	t_vec3	r_out_parallel;

	cos_theta = fmin(vec3_dot(vec3_minus(uv), n), 1.0);
	r_out_perp = vec3_mul2(vec3_add(vec3_mul2(n, cos_theta),
									uv), etai_over_etat);
	r_out_parallel = vec3_mul2(n,
						-sqrt(fabs(1.0 - vec3_length_squared(r_out_perp))));
	return (vec3_add(r_out_perp, r_out_parallel));
}
