/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_initialize.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 01:17:32 by seyu              #+#    #+#             */
/*   Updated: 2020/11/09 01:56:08 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "material/material.h"

#include "error.h"

t_material	*material_new(void)
{
	t_material	*mat;

	mat = (t_material *)malloc(sizeof(t_material));
	mat->emitted = material_virtual_emitted;
	return (mat);
}

void	material_delete(t_material **mat)
{
	((*mat)->del)((*mat)->condition);
	(*mat)->condition = NULL;
	free(*mat);
	*mat = NULL;
}
