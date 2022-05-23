/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 20:09:35 by seyu              #+#    #+#             */
/*   Updated: 2020/11/09 01:58:00 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

# include "mlx/mlx_color.h"

# include "raytracing/ray.h"
# include "raytracing/record.h"

struct s_material;
struct s_hit_record;

/*
**	t_ray2	ray
**	*(ray.ray1) = r_in
**	*(ray.ray2) = scattered
*/

struct	s_material
{
	void	(*del)(void *condition);
	t_color	(*emitted)(void *condition, double u, double v, t_point3 p);
	int		(*scatter)(void *condition, struct s_hit_record rec,
						t_color *attenuation, t_ray2 ray);
	void	*condition;
};
typedef	struct s_material	t_material;

struct	s_hit_record
{
	t_point3	p;
	t_vec3		normal;
	t_material	*mat_ptr;
	double		t;
	double		u;
	double		v;
	int			front_face;
};
typedef	struct s_hit_record	t_hit_record;

/*
**	-----------------------------------
**	material_initialize.c
**	-----------------------------------
*/

t_material	*material_new(void);
void		material_delete(t_material **mat);

t_color		material_virtual_emitted
					(void *condition, double u, double v, t_point3 p);

#endif
