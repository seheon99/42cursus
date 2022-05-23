/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:34:15 by seyu              #+#    #+#             */
/*   Updated: 2020/11/03 00:58:33 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITTABLE_H
# define HITTABLE_H

# include "libs/libft.h"

# include "raytracing/ray.h"
# include "raytracing/record.h"

/*
**	t_hittable
**
**	t_hittable can store all elements.
**	You must define the del to delete
**		and hit functions to determine if it is hitted the ray
**		and address the functions to del and hit.
**	Elements must be memory allocated and MUST BE FREE
**		by hittable_list_clear() functions with del function pointer
*/

struct	s_hittable
{
	void	(*del)(void *);
	int		(*hit)(void *, const t_ray, t_range, t_hit_record *);
	void	*element;
};
typedef	struct s_hittable	t_hittable;

#endif
