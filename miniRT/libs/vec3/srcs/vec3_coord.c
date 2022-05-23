/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_coord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 01:39:27 by seyu              #+#    #+#             */
/*   Updated: 2020/10/31 20:51:00 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

double	vec3_x(const t_vec3 v)
{
	return (v.e[0]);
}

double	vec3_y(const t_vec3 v)
{
	return (v.e[1]);
}

double	vec3_z(const t_vec3 v)
{
	return (v.e[2]);
}
