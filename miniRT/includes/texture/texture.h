/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 04:48:16 by seyu              #+#    #+#             */
/*   Updated: 2020/11/06 16:53:48 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "mlx/mlx_color.h"

# include "raytracing/point3.h"

struct	s_texture
{
	void	(*del)(void *map);
	t_color	(*value)(void *map, double u, double v, t_point3 p);
	void	*map;
};
typedef	struct s_texture	t_texture;

#endif
