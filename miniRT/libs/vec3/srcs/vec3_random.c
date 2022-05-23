/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_random.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:01:54 by seyu              #+#    #+#             */
/*   Updated: 2020/11/06 02:09:51 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include "utils.h"

t_vec3	vec3_random(double min, double max)
{
	return (vec3_create(random_double(min, max),
						random_double(min, max),
						random_double(min, max)));
}

t_vec3	vec3_random_in_sphere(double r)
{
	t_vec3	rtn;

	if (r == 0)
		return (vec3_create_empty());
	r = (r > 0 ? r : -r);
	while (1)
	{
		rtn = vec3_random(-r, r);
		if (vec3_length_squared(rtn) >= r)
			continue ;
		return (rtn);
	}
}

t_vec3	vec3_random_unit_vector(void)
{
	t_vec3	rtn;

	rtn = vec3_random_in_sphere(1);
	rtn = vec3_unit_vector(rtn);
	return (rtn);
}

t_vec3	vec3_random_in_hemisphere(const t_vec3 normal)
{
	t_vec3	in_unit_sphere;

	in_unit_sphere = vec3_random_in_sphere(1);
	if (vec3_dot(in_unit_sphere, normal) > 0)
		return (in_unit_sphere);
	else
		return (vec3_minus(in_unit_sphere));
}

t_vec3	vec3_random_in_unit_disk()
{
	t_vec3	p;

	while (1)
	{
		p = vec3_create(random_double(-1, 1), random_double(-1, 1), 0);
		if (vec3_length_squared(p) >= 1)
			continue ;
		return (p);
	}
}
