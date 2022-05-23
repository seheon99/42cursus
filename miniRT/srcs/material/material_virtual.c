/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_virtual.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 01:53:24 by seyu              #+#    #+#             */
/*   Updated: 2020/11/09 01:56:20 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx_color.h"

#include "material/material.h"

t_color	material_virtual_emitted
				(void *condition, double u, double v, t_point3 p)
{
	condition = 0;
	u = 0;
	v = 0;
	p = vec3_create_empty();
	return (color_create(0, 0, 0));
}
