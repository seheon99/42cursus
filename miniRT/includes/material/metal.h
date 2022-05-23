/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metal.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 02:17:10 by seyu              #+#    #+#             */
/*   Updated: 2020/11/09 01:33:37 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef METAL_H
# define METAL_H

# include "mlx/mlx_color.h"

# include "material/material.h"

struct		s_metal
{
	t_color	albedo;
	double	fuzz;
};
typedef	struct s_metal	t_metal;

/*
**	-----------------------------------
**	metal_initialize.c
**	-----------------------------------
*/

t_material	*metal_new(t_color a, double f);
void		metal_delete(void *condition);

/*
**	-----------------------------------
**	metal_scatter.c
**	-----------------------------------
*/

/*
**	t_ray2	ray
**	*(ray.ray1) = r_in
**	*(ray.ray2) = scattered
*/

int			metal_scatter(void *metal, t_hit_record rec,
									t_color *attenuation, t_ray2 ray);

#endif
