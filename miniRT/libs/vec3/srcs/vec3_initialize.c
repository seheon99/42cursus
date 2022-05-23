/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_initialize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 02:21:26 by seyu              #+#    #+#             */
/*   Updated: 2020/11/02 16:08:32 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec3	vec3_create(double e0, double e1, double e2)
{
	t_vec3	rtn;

	rtn.e[0] = e0;
	rtn.e[1] = e1;
	rtn.e[2] = e2;
	return (rtn);
}

t_vec3	vec3_create_empty()
{
	t_vec3	rtn;

	rtn.e[0] = 0;
	rtn.e[1] = 0;
	rtn.e[2] = 0;
	return (rtn);
}
