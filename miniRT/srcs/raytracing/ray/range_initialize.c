/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_initialize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 01:52:16 by seyu              #+#    #+#             */
/*   Updated: 2020/11/01 01:52:58 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing/ray.h"

t_range	range_create(double min, double max)
{
	t_range	range;

	range.min = min;
	range.max = max;
	return (range);
}
