/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_texture_value.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:24:21 by seyu              #+#    #+#             */
/*   Updated: 2020/11/06 17:07:10 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/vec3.h"

#include "mlx/mlx_color.h"

#include "texture/texture.h"
#include "texture/checker_texture.h"

t_color	checker_texture_value(void *map, double u, double v, t_vec3 p)
{
	t_checker_texture	*check;
	double				sines;

	check = map;
	sines = sin(10 * vec3_x(p)) * sin(10 * vec3_y(p)) * sin(10 * vec3_z(p));
	if (sines < 0)
		return (check->odd->value(check->odd->map, u, v, p));
	else
		return (check->even->value(check->even->map, u, v, p));
}
