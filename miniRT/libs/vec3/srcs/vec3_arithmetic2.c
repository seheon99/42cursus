/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_arithmetic2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 01:57:58 by seyu              #+#    #+#             */
/*   Updated: 2020/10/31 20:51:01 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec3	vec3_mul2(const t_vec3 v, const double d)
{
	t_vec3	rtn;

	rtn.e[0] = v.e[0] * d;
	rtn.e[1] = v.e[1] * d;
	rtn.e[2] = v.e[2] * d;
	return (rtn);
}

t_vec3	vec3_div2(const t_vec3 v, const double d)
{
	t_vec3	rtn;

	rtn.e[0] = v.e[0] / d;
	rtn.e[1] = v.e[1] / d;
	rtn.e[2] = v.e[2] / d;
	return (rtn);
}
