/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point3.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:34:44 by seyu              #+#    #+#             */
/*   Updated: 2020/11/02 00:51:22 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT3_H
# define POINT3_H

# include "libs/vec3.h"

typedef	t_vec3	t_point3;

/*
**	-----------------------------------
**	point3_initialize.c
**	-----------------------------------
*/

t_point3	point3_create(double x, double y, double z);
double		point3_x(t_point3 p);
double		point3_y(t_point3 p);
double		point3_z(t_point3 p);

#endif
