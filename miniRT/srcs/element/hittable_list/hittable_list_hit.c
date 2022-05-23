/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_list_hit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 02:10:15 by seyu              #+#    #+#             */
/*   Updated: 2020/11/06 13:40:40 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing/ray.h"
#include "raytracing/record.h"

#include "element/hittable_list.h"

int		hittable_list_hit(
	t_hittable_list *list,
	const t_ray r,
	const t_range t_minmax,
	t_hit_record *rec)
{
	t_hit_record	temp_rec;
	t_list			*itr;
	t_hittable		*object;
	int				hit_anything;
	double			closest_so_far;

	hit_anything = FALSE;
	closest_so_far = t_minmax.max;
	itr = list->objects;
	while (itr)
	{
		object = itr->content;
		if (object->hit(object->element, r,
				range_create(t_minmax.min, closest_so_far), &temp_rec))
		{
			hit_anything = TRUE;
			closest_so_far = temp_rec.t;
			record_copy(rec, temp_rec);
		}
		itr = itr->next;
	}
	return (hit_anything);
}
