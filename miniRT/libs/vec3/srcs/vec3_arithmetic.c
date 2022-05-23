/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_arithmetic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 01:42:23 by seyu              #+#    #+#             */
/*   Updated: 2020/10/31 20:51:02 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec3	vec3_minus(const t_vec3 v)
{
	t_vec3	rtn;

	rtn.e[0] = -(v.e[0]);
	rtn.e[1] = -(v.e[1]);
	rtn.e[2] = -(v.e[2]);
	return (rtn);
}

t_vec3	vec3_add(const t_vec3 v1, const t_vec3 v2)
{
	t_vec3	rtn;

	rtn.e[0] = v1.e[0] + v2.e[0];
	rtn.e[1] = v1.e[1] + v2.e[1];
	rtn.e[2] = v1.e[2] + v2.e[2];
	return (rtn);
}

t_vec3	vec3_sub(const t_vec3 v1, const t_vec3 v2)
{
	t_vec3	rtn;

	rtn.e[0] = v1.e[0] - v2.e[0];
	rtn.e[1] = v1.e[1] - v2.e[1];
	rtn.e[2] = v1.e[2] - v2.e[2];
	return (rtn);
}

t_vec3	vec3_mul(const t_vec3 v1, const t_vec3 v2)
{
	t_vec3	rtn;

	rtn.e[0] = v1.e[0] * v2.e[0];
	rtn.e[1] = v1.e[1] * v2.e[1];
	rtn.e[2] = v1.e[2] * v2.e[2];
	return (rtn);
}
