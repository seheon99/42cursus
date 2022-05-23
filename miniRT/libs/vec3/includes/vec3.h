/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 01:23:46 by seyu              #+#    #+#             */
/*   Updated: 2020/11/06 02:15:53 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

# include <math.h>

struct	s_vec3
{
	double	e[3];
};
typedef	struct s_vec3	t_vec3;

/*
**	-----------------------------------
**	vec3_initialize.c
**	-----------------------------------
*/

t_vec3	vec3_create(double e0, double e1, double e2);
t_vec3	vec3_create_empty();

/*
**	-----------------------------------
**	vec3_random.c
**	-----------------------------------
*/

t_vec3	vec3_random(double min, double max);
t_vec3	vec3_random_in_sphere(double max);
t_vec3	vec3_random_unit_vector(void);
t_vec3	vec3_random_in_hemisphere(const t_vec3 normal);
t_vec3	vec3_random_in_unit_disk();

/*
**	-----------------------------------
**	vec3_coord.c
**	-----------------------------------
*/

double	vec3_x(const t_vec3 v);
double	vec3_y(const t_vec3 v);
double	vec3_z(const t_vec3 v);

/*
**	-----------------------------------
**	vec3_arithmetic.c
**	-----------------------------------
*/

t_vec3	vec3_minus(const t_vec3 v);
t_vec3	vec3_add(const t_vec3 v1, const t_vec3 v2);
t_vec3	vec3_sub(const t_vec3 v1, const t_vec3 v2);
t_vec3	vec3_mul(const t_vec3 v1, const t_vec3 v2);

/*
**	-----------------------------------
**	vec3_arithmetic2.c
**	-----------------------------------
*/

t_vec3	vec3_mul2(const t_vec3 v, const double d);
t_vec3	vec3_div2(const t_vec3 v, const double d);

/*
**	-----------------------------------
**	vec3_product.c
**	-----------------------------------
*/

double	vec3_dot(const t_vec3 u, const t_vec3 v);
t_vec3	vec3_cross(const t_vec3 u, const t_vec3 v);

/*
**	-----------------------------------
**	vec3_utils.c
**	-----------------------------------
*/

t_vec3	vec3_unit_vector(const t_vec3 v);
double	vec3_length(const t_vec3 v);
double	vec3_length_squared(const t_vec3 v);
int		vec3_is_near_zero(const t_vec3 v);

/*
**	-----------------------------------
**	vec3_ray.c
**	-----------------------------------
*/

t_vec3	vec3_reflect(const t_vec3 v, const t_vec3 n);
t_vec3	vec3_refract(const t_vec3 uv, const t_vec3 n, double etai_over_etat);

#endif
