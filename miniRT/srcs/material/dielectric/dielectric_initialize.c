/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dielectric_initialize.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:42:02 by seyu              #+#    #+#             */
/*   Updated: 2020/11/09 01:57:06 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mlx/mlx_color.h"

#include "material/material.h"
#include "material/dielectric.h"

t_material	*dielectric_new(double index_of_refraction)
{
	t_material	*mat;

	mat = material_new();
	mat->del = dielectric_delete;
	mat->scatter = dielectric_scatter;
	mat->condition = (t_dielectric *)malloc(sizeof(t_dielectric));
	((t_dielectric *)(mat->condition))->ir = index_of_refraction;
	return (mat);
}

void		dielectric_delete(void *condition)
{
	free(condition);
}
