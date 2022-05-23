/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solid_color_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 13:06:02 by seyu              #+#    #+#             */
/*   Updated: 2020/11/06 17:07:35 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx_color.h"

#include "texture/texture.h"
#include "texture/solid_color.h"

t_color	solid_color_value(void *map, double u, double v, t_vec3 p)
{
	t_solid_color	*solid_color;

	u = 0;
	v = 0;
	p = vec3_create_empty();
	solid_color = map;
	return (solid_color->color_value);
}
