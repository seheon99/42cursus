/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_get_uv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 05:11:08 by seyu              #+#    #+#             */
/*   Updated: 2020/11/07 15:00:51 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "raytracing/ray.h"
#include "raytracing/point3.h"

/*
**	p: a given point on the sphere of radius one, centered at the origin
**	u: returned value [0, 1] of angle around the Y axis from X = -1.
**	v: returned value [0, 1] of angle from Y = -1 to Y = +1;
**		<1 0 0> yields <0.50 0.50>		<-1  0  0> yields <0.00 0.50>
**		<0 1 0> yields <0.50 1.00>		< 0 -1  0> yields <0.50 0.00>
**		<0 0 1> yields <0.25 0.50>		< 0  0 -1> yields <0.75 0.50>
*/

void	sphere_get_uv(const t_point3 p, double *u, double *v)
{
	double	theta;
	double	phi;

	theta = acos(-point3_y(p));
	phi = atan2(-point3_z(p), point3_x(p)) + M_PI;
	*u = phi / (2 * M_PI);
	*v = theta / M_PI;
}
