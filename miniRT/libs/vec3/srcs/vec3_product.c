/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_product.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 02:10:25 by seyu              #+#    #+#             */
/*   Updated: 2020/10/31 20:51:04 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

double	vec3_dot(const t_vec3 u, const t_vec3 v)
{
	return ((u.e[0] * v.e[0])
			+ (u.e[1] * v.e[1])
			+ (u.e[2] * v.e[2]));
}

t_vec3	vec3_cross(const t_vec3 u, const t_vec3 v)
{
	return (vec3_create(u.e[1] * v.e[2] - u.e[2] * v.e[1],
						u.e[2] * v.e[0] - u.e[0] * v.e[2],
						u.e[0] * v.e[1] - u.e[1] * v.e[0]));
}
