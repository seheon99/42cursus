/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:20:44 by seyu              #+#    #+#             */
/*   Updated: 2020/11/02 01:17:04 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/*
**	-----------------------------------
**	utils_math.c
**	-----------------------------------
*/

double	random_double(double min, double max);
double	degrees_to_radians(double degrees);
double	clamp(double x, double min, double max);

#endif
