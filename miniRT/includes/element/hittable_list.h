/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_list.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 01:00:55 by seyu              #+#    #+#             */
/*   Updated: 2020/11/02 20:09:39 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITTABLE_LIST_H
# define HITTABLE_LIST_H

# define TRUE 1
# define FALSE 0

# include "libs/libft.h"

# include "raytracing/ray.h"
# include "raytracing/record.h"

# include "element/hittable.h"

/*
**	t_hittable_list
**
**	t_hittable_list is just a t_list pointer holder
**	After hittable_list_new to create new t_hittable_list structure,
**		you have to do use hittable_list_delete after everything is done,
**		otherwise MEMORY LEAK may occur.
*/

struct	s_hittable_list
{
	t_list	*objects;
};
typedef	struct s_hittable_list	t_hittable_list;

/*
**	-----------------------------------
**	hittable_list_init.c
**	-----------------------------------
*/

t_hittable_list
		*hittable_list_new(void *object);
void	hittable_list_add(t_hittable_list *lst, void *object);
void	hittable_list_clear(t_hittable_list *lst);
void	hittable_list_delete(t_hittable_list **lst);

/*
**	-----------------------------------
**	hittable_list_hit.c
**	-----------------------------------
*/

int		hittable_list_hit(
			t_hittable_list *list,
			const t_ray r,
			const t_range t_minmax,
			t_hit_record *rec);

#endif
