/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 00:52:50 by seyu              #+#    #+#             */
/*   Updated: 2020/11/07 04:23:42 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx_color.h"
#include "mlx/mlx_image.h"

int		image_color_scale(t_image *image)
{
	int	color_scale;

	color_scale = pow(2,
		image->bits_per_pixel / (image->line_length / image->width))
		- 1;
	return (color_scale);
}

unsigned int
		image_pixel_get(t_image *image, int x, int y)
{
	char			*dst;
	unsigned int	color;

	if (!image)
		return (1);
	dst = image->addr
			+ (((image->height - 1) - y) * image->line_length)
			+ (x * (image->bits_per_pixel / 8));
	color = *(unsigned int *)dst;
	return (color);
}

t_color	image_pixel_get_color(t_image *image, int x, int y)
{
	t_color			color;
	unsigned int	color_hex;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	color_hex = image_pixel_get(image, x, y);
	r = (color_hex & 0xFF0000) >> 16;
	g = (color_hex & 0xFF00) >> 8;
	b = (color_hex & 0xFF);
	color = color_create(r / 255.0, g / 255.0, b / 255.0);
	return (color);
}

int		image_pixel_put(t_image *img, int x, int y, t_color color)
{
	char	*dst;

	if (!img)
		return (1);
	dst = img->addr
			+ (((img->height - 1) - y) * img->line_length)
			+ (x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color_get_trgb(color);
	return (0);
}
