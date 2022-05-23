/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point3_initialize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:37:02 by seyu              #+#    #+#             */
/*   Updated: 2020/11/06 13:13:11 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing/point3.h"

t_point3	point3_create(double x, double y, double z)
{
	t_point3	p;

	p.e[0] = x;
	p.e[1] = y;
	p.e[2] = z;
	return (p);
}

double		point3_x(t_point3 p)
{
	return (p.e[0]);
}

double		point3_y(t_point3 p)
{
	return (p.e[1]);
}

double		point3_z(t_point3 p)
{
	return (p.e[2]);
}
