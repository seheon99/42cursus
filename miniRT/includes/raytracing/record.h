/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 00:22:02 by seyu              #+#    #+#             */
/*   Updated: 2020/11/06 05:18:01 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECORD_H
# define RECORD_H

# include "libs/vec3.h"

# include "raytracing/point3.h"
# include "raytracing/ray.h"

# include "material/material.h"

typedef	struct s_hit_record	t_hit_record;

/*
**	-----------------------------------
**	hit_record_initialize.c
**	-----------------------------------
*/

void	record_copy(t_hit_record *dst, t_hit_record src);

void	record_set_face_normal(
				t_hit_record *record,
				const t_ray r,
				const t_vec3 outward_normal);

#endif
