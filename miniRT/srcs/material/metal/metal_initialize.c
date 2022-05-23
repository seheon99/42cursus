/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metal_initialize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 02:20:43 by seyu              #+#    #+#             */
/*   Updated: 2020/11/09 01:56:35 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mlx/mlx_color.h"

#include "material/material.h"
#include "material/metal.h"

t_material	*metal_new(t_color a, double f)
{
	t_material	*mat;

	mat = material_new();
	mat->del = metal_delete;
	mat->scatter = metal_scatter;
	mat->condition = (t_metal *)malloc(sizeof(t_metal));
	((t_metal *)(mat->condition))->albedo = a;
	((t_metal *)(mat->condition))->fuzz = (f < 1 ? f : 1);
	return (mat);
}

void		metal_delete(void *condition)
{
	free(condition);
}
