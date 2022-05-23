/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lambertian.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 01:02:02 by seyu              #+#    #+#             */
/*   Updated: 2020/11/06 17:23:46 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LAMBERTIAN_H
# define LAMBERTIAN_H

# include "mlx/mlx_color.h"

# include "material/material.h"
# include "texture/texture.h"

struct	s_lambertian
{
	t_texture	*albedo;
};
typedef	struct s_lambertian	t_lambertian;

/*
**	-----------------------------------
**	lambertian_initialize.c
**	-----------------------------------
*/

t_material	*lambertian_new(t_texture *a);
t_material	*lambertian_new_color(t_color c);
t_material	*lambertian_new_rgb(double r, double g, double b);
void		lambertian_delete(void *condition);

/*
**	-----------------------------------
**	lambertian_scatter.c
**	-----------------------------------
*/

/*
**	t_ray2	ray
**	ray.ray1 = &(r_in)
**	ray.ray2 = &(scattered)
*/

int			lambertian_scatter(void *lamb, t_hit_record rec,
									t_color *attenuation, t_ray2 ray);

#endif
