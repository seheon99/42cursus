/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solid_color.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 04:50:56 by seyu              #+#    #+#             */
/*   Updated: 2020/11/06 17:07:16 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLID_COLOR_H
# define SOLID_COLOR_H

# include "mlx/mlx_color.h"

# include "texture/texture.h"

struct	s_solid_color
{
	t_color	color_value;
};
typedef	struct s_solid_color	t_solid_color;

/*
**	-----------------------------------
**	solid_color_initialize.c
**	-----------------------------------
*/

t_texture	*solid_color_new(t_color c);
t_texture	*solid_color_new_rgb(double red, double green, double blue);
void		solid_color_delete(void *map);

/*
**	-----------------------------------
**	solid_color_value.c
**	-----------------------------------
*/

t_color		solid_color_value(void *map, double u, double v, t_vec3 p);

#endif
