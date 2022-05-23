/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse_light.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 04:45:06 by seyu              #+#    #+#             */
/*   Updated: 2020/11/09 01:41:28 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIFFUSE_LIGHT_H
# define DIFFUSE_LIGHT_H

# include "mlx/mlx_color.h"

# include "material/material.h"
# include "texture/texture.h"

struct	s_diffuse_light
{
	t_texture	*emit;
};
typedef	struct s_diffuse_light	t_diffuse_light;

t_material	*diffuse_light_new(t_texture *a);
t_material	*diffuse_light_new_color(t_color c);
t_material	*diffuse_light_new_rgb(double r, double g, double b);
void		diffuse_light_delete(void *condition);

int			diffuse_light_scatter(void *light,
						t_hit_record rec, t_color *attenuation, t_ray2 ray);
t_color		diffuse_light_emitted(void *light,
						double u, double v, t_point3 p);

#endif
