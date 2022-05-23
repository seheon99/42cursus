/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_texture_initialize.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:09:35 by seyu              #+#    #+#             */
/*   Updated: 2020/11/06 16:56:25 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mlx/mlx_color.h"

#include "texture/texture.h"
#include "texture/solid_color.h"
#include "texture/checker_texture.h"

t_texture	*checker_texture_new(t_texture *o, t_texture *e)
{
	t_texture			*check;

	check = (t_texture *)malloc(sizeof(t_texture));
	check->del = checker_texture_delete;
	check->value = checker_texture_value;
	check->map = (t_checker_texture *)malloc(sizeof(t_checker_texture));
	((t_checker_texture *)(check->map))->odd = o;
	((t_checker_texture *)(check->map))->even = e;
	return (check);
}

t_texture	*checker_texture_new_color(t_color o, t_color e)
{
	t_texture	*odd;
	t_texture	*even;

	odd = solid_color_new(o);
	even = solid_color_new(e);
	return (checker_texture_new(odd, even));
}

void		checker_texture_delete(void *map)
{
	t_texture	*odd;
	t_texture	*even;

	odd = ((t_checker_texture *)map)->odd;
	odd->del(odd);
	((t_checker_texture *)map)->odd = NULL;
	even = ((t_checker_texture *)map)->even;
	even->del(even);
	((t_checker_texture *)map)->even = NULL;
	free(map);
}
