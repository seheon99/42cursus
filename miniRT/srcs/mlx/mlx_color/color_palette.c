/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_palette.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 02:45:33 by seyu              #+#    #+#             */
/*   Updated: 2020/11/02 04:30:25 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx_color.h"

#include "utils.h"

int	color_get_t()
{
	return (0);
}

int	color_get_r(t_color color)
{
	double	r;

	r = color.e[0];
	r /= SAMPLES_PER_PIXEL;
	r = sqrt(r);
	return (256 * clamp(r, 0, 0.999));
}

int	color_get_g(t_color color)
{
	double	g;

	g = color.e[1];
	g /= SAMPLES_PER_PIXEL;
	g = sqrt(g);
	return (256 * clamp(g, 0, 0.999));
}

int	color_get_b(t_color color)
{
	double	b;

	b = color.e[2];
	b /= SAMPLES_PER_PIXEL;
	b = sqrt(b);
	return (256 * clamp(b, 0, 0.999));
}

unsigned int
	color_get_trgb(t_color color)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = color_get_t() & 0xFF;
	r = color_get_r(color) & 0xFF;
	g = color_get_g(color) & 0xFF;
	b = color_get_b(color) & 0xFF;
	return ((t << 24) | (r << 16) | (g << 8) | b);
}
