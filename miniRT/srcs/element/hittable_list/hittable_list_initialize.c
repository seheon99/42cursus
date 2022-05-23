/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_list_initialize.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 01:12:42 by seyu              #+#    #+#             */
/*   Updated: 2020/11/06 00:24:30 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "raytracing/ray.h"
#include "raytracing/record.h"

#include "element/hittable_list.h"

t_hittable_list
		*hittable_list_new(void *object)
{
	t_hittable_list	*lst;

	lst = (t_hittable_list *)malloc(sizeof(t_hittable_list));
	if (!object)
		lst->objects = NULL;
	else
		lst->objects = ft_lstnew(object);
	return (lst);
}

void	hittable_list_add(t_hittable_list *lst, void *object)
{
	if (lst->objects)
		ft_lstadd_back(&(lst->objects), ft_lstnew(object));
	else
		lst->objects = ft_lstnew(object);
}

void	hittable_list_clear(t_hittable_list *lst)
{
	t_list	*next;

	while (lst->objects)
	{
		next = lst->objects->next;
		ft_lstdelone(lst->objects,
				((t_hittable *)(lst->objects->content))->del);
		free(lst->objects);
		lst->objects = next;
	}
}

void	hittable_list_delete(t_hittable_list **lst)
{
	hittable_list_clear(*lst);
	free(*lst);
	*lst = NULL;
}
