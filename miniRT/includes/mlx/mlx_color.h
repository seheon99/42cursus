/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_color.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 22:30:39 by seyu              #+#    #+#             */
/*   Updated: 2020/11/02 05:13:08 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_COLOR_H
# define MLX_COLOR_H

# include "libs/vec3.h"

# define SAMPLES_PER_PIXEL	50

typedef	t_vec3	t_color;

/*
**	-----------------------------------
**	color_initialize.c
**	-----------------------------------
*/

t_color			color_create(double r, double g, double b);

/*
**	-----------------------------------
**	color_palette.c
**	-----------------------------------
*/

int				color_get_t();
int				color_get_r(t_color color);
int				color_get_g(t_color color);
int				color_get_b(t_color color);
unsigned int	color_get_trgb(t_color color);

#endif
