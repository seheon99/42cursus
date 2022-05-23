/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dielectric.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:27:55 by seyu              #+#    #+#             */
/*   Updated: 2020/11/06 16:49:49 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIELECTRIC_H
# define DIELECTRIC_H

# include "mlx/mlx_color.h"

# include "material/material.h"

struct	s_dielectric
{
	double ir;
};
typedef	struct s_dielectric	t_dielectric;

/*
**	-----------------------------------
**	dielectric_initialize.c
**	-----------------------------------
*/

t_material	*dielectric_new(double index_of_refraction);
void		dielectric_delete(void *condition);

/*
**	-----------------------------------
**	dielectric_scatter.c
**	-----------------------------------
*/

/*
**	t_ray2	ray
**	*(ray.ray1) = r_in
**	*(ray.ray2) = scattered
*/

int			dielectric_scatter(void *dielectric, t_hit_record rec,
										t_color *attenuation, t_ray2 ray);

/*
**	-----------------------------------
**	dielectric_reflectance.c
**	-----------------------------------
*/

double		dielectric_reflactance(double cosine, double ref_idx);

#endif
