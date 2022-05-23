/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 01:21:45 by seyu              #+#    #+#             */
/*   Updated: 2020/11/09 02:20:20 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
**	-----------------------------------
**	Library Headerfiles
**	-----------------------------------
*/

#include "libs/mlx.h"
#include "libs/libft.h"
#include "libs/ft_printf.h"
#include "libs/vec3.h"

/*
**	-----------------------------------
**	Sources Headerfiles
**	-----------------------------------
*/

#include "mlx/mlx_color.h"
#include "mlx/mlx_image.h"
#include "mlx/mlx_window.h"

#include "raytracing/ray.h"
#include "raytracing/record.h"
#include "raytracing/camera.h"

#include "element/hittable.h"
#include "element/hittable_list.h"
#include "element/sphere.h"

#include "material/material.h"
#include "material/lambertian.h"
#include "material/metal.h"
#include "material/dielectric.h"
#include "material/diffuse_light.h"

#include "texture/texture.h"
#include "texture/solid_color.h"
#include "texture/checker_texture.h"
#include "texture/image_texture.h"

#include "error.h"
#include "utils.h"

/*
**	-----------------------------------
**	Ray Functions
**	-----------------------------------
*/

static t_color
	ray_color(t_ray r, t_hittable_list *world, int depth)
{
	t_hit_record	rec;
	t_color			background;
	t_ray			scattered;
	t_color			attenuation;
	t_color			emitted;

	background = color_create(0, 0, 0);
	if (depth <= 0)
		return (color_create(0, 0, 0));
	if (!(hittable_list_hit(world, r, range_create(0.001, INFINITY), &rec)))
		return (background);

	emitted = rec.mat_ptr->emitted(rec.mat_ptr->condition, rec.u, rec.v, rec.p);
	if (!(rec.mat_ptr->scatter(rec.mat_ptr->condition, rec, &attenuation, ray2_create(&r, &scattered))))
		return (emitted);
	return (vec3_add(
		emitted,
		vec3_mul(attenuation, ray_color(scattered, world, depth - 1))
	));
}

/*
**	-----------------------------------
**	Main Functions
**	-----------------------------------
*/

/*
**	One material per element must be used,
**		otherwise double free error will be occured
*/

// static t_hittable_list
// 	*random_scene()
// {
// 	t_hittable_list	*world;
// 	t_material		*mat;
// 	t_texture		*texture;
// 	t_point3		center;
// 	int				a;
// 	int				b;

// 	texture = checker_texture_new_color(color_create(0.2, 0.3 ,0.1),
// 									color_create(0.9, 0.9, 0.9));
// 	mat = lambertian_new(texture);
// 	world = hittable_list_new(sphere_new(point3_create(0, -1000, 0), 1000, mat));
// 	a = -12;
// 	while (++a < 11)
// 	{
// 		b = -12;
// 		while (++b < 11)
// 		{
// 			center = point3_create(a + 0.9 * random_double(0, 1), 0.2, b + 0.9 * random_double(0, 1));
// 			if (vec3_length(vec3_sub(center, point3_create(4, 0.2, 0))) > 0.9)
// 			{
// 				if (random_double(0, 1) < 0.8)
// 					mat = lambertian_new_color(vec3_mul(vec3_random(0, 1), vec3_random(0, 1)));
// 				else if (random_double(0, 1) < 0.75)
// 					mat = metal_new(vec3_random(0, 1), random_double(0, 0.5));
// 				else
// 					mat = dielectric_new(1.5);
// 				hittable_list_add(world, sphere_new(center, 0.2, mat));
// 			}
// 		}
// 	}

// 	mat = dielectric_new(1.5);
// 	hittable_list_add(world, sphere_new(point3_create(0, 1, 0), 1.0, mat));
// 	mat = lambertian_new_rgb(0.4, 0.2, 0.1);
// 	hittable_list_add(world, sphere_new(point3_create(-4, 1, 0), 1.0, mat));
// 	mat = metal_new(color_create(0.7, 0.6, 0.5), 0.0);
// 	hittable_list_add(world, sphere_new(point3_create(4, 1, 0), 1.0, mat));
// 	return (world);
// }

// static t_hittable_list
// 	*earth(t_window *win)
// {
// 	t_hittable_list	*world;
// 	t_texture		*texture;
// 	t_material		*material;
// 	t_image			*srcimg;

// 	srcimg = window_new_source(win, "earthmap.png");
// 	texture = image_texture_new(srcimg);
// 	material = lambertian_new(texture);
// 	world = hittable_list_new(sphere_new(point3_create(0, 0, 0), 2, material));
// 	return (world);
// }

static t_hittable_list
	*simple_light()
{
	t_hittable_list	*world;
	t_material		*pertext;
	t_material		*difflight;

	world = hittable_list_new(NULL);
	pertext = lambertian_new_rgb(0.1, 0.1, 0.1);
	hittable_list_add(world, sphere_new(point3_create(0, -1000, 0), 1000, pertext));
	pertext = lambertian_new_rgb(0.1, 0.1, 0.1);
	hittable_list_add(world, sphere_new(point3_create(0, 2, 0), 2, pertext));
	difflight = diffuse_light_new_rgb(4, 4, 4);
	hittable_list_add(world, sphere_new(point3_create(0, 7, 0), 2, difflight));
	return (world);
}

static void
	make_my_image(t_image *img, int image_width, int image_height)
{
	int		x;
	int		y;
	int		samples;

	t_color	pixel_color;
	t_ray	r;

	t_hittable_list	*world = simple_light();

	t_point3	lookfrom = point3_create(13, 2, 3);
	t_point3	lookat = point3_create(0, 2, 0);
	t_vec3		vup = vec3_create(0, 1, 0);
	double		aspect_ratio = (double)image_width / image_height;
	double		dist_to_focus = 10;
	double		aperture = 0;

	t_camera	cam;
	cam = camera_create(lookfrom, lookat, vup, 40, aspect_ratio, aperture, dist_to_focus);

	y = -1;
	while (++y < image_height)
	{
		ft_printf("\rScanlines remaining: %d%% ", y * 100 / image_height);
		x = -1;
		while (++x < image_width)
		{
			pixel_color = color_create(0, 0, 0);
			samples = -1;
			while (++samples < SAMPLES_PER_PIXEL)
			{
				r = camera_get_ray(cam,
					((double)x + random_double(0, 1)) / (image_width - 1),
					((double)y + random_double(0, 1)) / (image_height - 1));
				pixel_color = vec3_add(pixel_color,
						ray_color(r, world, MAX_DEPTH));
			}
			image_pixel_put(img, x, y, pixel_color);
		}
	}
	hittable_list_delete(&world);
	ft_printf("\rScanlines remaining: %d%% ", 100);
	ft_printf("\nDone.\n");
}

static void
	hook(t_window **win)
{
	mlx_hook((*win)->mlx_win, DESTROYNOTIFY, STRUCTURENOTIFYMASK,
					window_delete, win);
	mlx_hook((*win)->mlx_win, KEYPRESS, KEYPRESSMASK,
					window_keypress, win);
}

#define	WIDTH	960
#define	HEIGHT	540

int	main(int argc, char **argv)
{
	t_window	*window;
	t_image		*image;

	if (argc != 2 && argc != 3)
		error_usage(argv[0]);
	window = window_new(WIDTH, HEIGHT, "Hello, World!");
	image = window_new_image(window, WIDTH, HEIGHT);
	make_my_image(image, WIDTH, HEIGHT);
	if (argc == 3 && ft_strncmp(argv[2], "--save", 6) == 0)
		image_print_bmp(image, argv[0], argv[1]);
	window_put_next_image(window);
	hook(&window);
	mlx_loop(window->mlx);
}
