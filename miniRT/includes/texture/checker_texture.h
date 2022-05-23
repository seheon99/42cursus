/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_texture.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:05:31 by seyu              #+#    #+#             */
/*   Updated: 2020/11/06 17:46:49 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_TEXTURE_H
# define CHECKER_TEXTURE_H

# include "mlx/mlx_color.h"

# include "texture/texture.h"

struct	s_checker_texture
{
	t_texture	*odd;
	t_texture	*even;
};
typedef	struct s_checker_texture	t_checker_texture;

/*
**	-----------------------------------
**	checker_texture_initialize.c
**	-----------------------------------
*/

t_texture	*checker_texture_new(t_texture *o, t_texture *e);
t_texture	*checker_texture_new_color(t_color o, t_color e);
void		checker_texture_delete(void *map);

/*
**	-----------------------------------
**	checker_texture_value.c
**	-----------------------------------
*/

t_color		checker_texture_value(void *map, double u, double v, t_vec3 p);

#endif
