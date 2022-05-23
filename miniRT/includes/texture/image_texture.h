/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_texture.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 17:43:31 by seyu              #+#    #+#             */
/*   Updated: 2020/11/07 02:07:31 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_TEXTURE_H
# define IMAGE_TEXTURE_H

# include "mlx/mlx_color.h"
# include "mlx/mlx_image.h"

# include "texture/texture.h"

struct	s_image_texture
{
	t_image	*img;
};
typedef	struct s_image_texture	t_image_texture;

/*
**	-----------------------------------
**	image_texture_initialize.c
**	-----------------------------------
*/

t_texture	*image_texture_new(t_image *img);
void		image_texture_delete(void *map);

/*
**	-----------------------------------
**	image_texture_value.c
**	-----------------------------------
*/

t_color		image_texture_value(void *map, double u, double v, t_vec3 p);

#endif
