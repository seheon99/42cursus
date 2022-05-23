/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_print_bmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 22:54:51 by seyu              #+#    #+#             */
/*   Updated: 2020/11/05 02:16:57 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#include "libs/ft_printf.h"
#include "libs/libft.h"

#include "mlx/mlx_color.h"
#include "mlx/mlx_image.h"

#include "utils.h"

static void
	bmp_write_file_header(int fd, t_image *img)
{
	t_bmp_file_header	file_header;
	int					offbits;
	int					img_size;

	offbits = 0x36;
	img_size = img->width * img->height * 4;
	file_header.bf_type = ('M' << 8) | 'B';
	file_header.bf_size = img_size + offbits;
	file_header.bf_reserved1 = 0;
	file_header.bf_reserved2 = 0;
	file_header.bf_offbits = offbits;
	write(fd, &(file_header.bf_type), 2);
	write(fd, &(file_header.bf_size), 4);
	write(fd, &(file_header.bf_reserved1), 2);
	write(fd, &(file_header.bf_reserved2), 2);
	write(fd, &(file_header.bf_offbits), 4);
}

static void
	bmp_write_info_header(int fd, t_image *img)
{
	t_bmp_info_header	info_header;

	info_header.bi_size = sizeof(t_bmp_info_header);
	info_header.bi_width = img->width;
	info_header.bi_height = img->height;
	info_header.bi_planes = 1;
	info_header.bi_bit_count = 32;
	info_header.bi_compression = 0;
	info_header.bi_size_image = img->width * img->height * 4;
	info_header.bi_x_pels_per_meter = 2835;
	info_header.bi_y_pels_per_meter = 2835;
	info_header.bi_clr_used = 0;
	info_header.bi_clr_important = 0;
	write(fd, &(info_header.bi_size), 4);
	write(fd, &(info_header.bi_width), 4);
	write(fd, &(info_header.bi_height), 4);
	write(fd, &(info_header.bi_planes), 2);
	write(fd, &(info_header.bi_bit_count), 2);
	write(fd, &(info_header.bi_compression), 4);
	write(fd, &(info_header.bi_size_image), 4);
	write(fd, &(info_header.bi_x_pels_per_meter), 4);
	write(fd, &(info_header.bi_y_pels_per_meter), 4);
	write(fd, &(info_header.bi_clr_used), 4);
	write(fd, &(info_header.bi_clr_important), 4);
}

static void
	bmp_write_rgb(int fd, unsigned int color)
{
	t_rgb_triple	rgb;

	rgb.rgb_alpha = (color & (0xFF000000)) >> 24;
	rgb.rgb_red = (color & (0xFF0000)) >> 16;
	rgb.rgb_green = (color & (0xFF00)) >> 8;
	rgb.rgb_blue = (color & (0xFF));
	write(fd, &(rgb.rgb_blue), 1);
	write(fd, &(rgb.rgb_green), 1);
	write(fd, &(rgb.rgb_red), 1);
	write(fd, &(rgb.rgb_alpha), 1);
}

static int
	bmp_open(char *filepath, char *filename, char **target_file)
{
	int		fd;
	int		itr;
	char	**split_temp;

	*target_file = NULL;
	split_temp = ft_split(filepath, '/');
	itr = -1;
	while (split_temp[++itr + 1])
		ft_strjoin2(target_file, split_temp[itr]);
	ft_strjoin2(target_file, "/images/");
	ft_strjoin2(target_file, filename);
	ft_strjoin2(target_file, ".bmp");
	itr = -1;
	while (split_temp[++itr])
		free(split_temp[itr]);
	free(split_temp);
	if ((fd = open(*target_file, O_CREAT | O_WRONLY)) == -1)
		perror("bmp: failed to open file");
	return (fd);
}

int	image_print_bmp(t_image *img, char *filepath, char *filename)
{
	int				fd;
	int				x;
	int				y;
	char			*target_file;

	if ((target_file = ft_strnstr(filename, ".rt", ft_strlen(filename))))
		target_file[0] = '\0';
	if ((fd = bmp_open(filepath, filename, &target_file)) < 0)
		return (fd);
	bmp_write_file_header(fd, img);
	bmp_write_info_header(fd, img);
	y = -1;
	while (++y < img->height)
	{
		ft_printf("\rGenerating bmp file: %d%%", y * 100 / img->height);
		x = -1;
		while (++x < img->width)
			bmp_write_rgb(fd, image_pixel_get(img, x, y));
	}
	ft_printf("\rGeterating bmp file: %d%%", 100);
	ft_printf("\n.bmp file created at the following path: %s\n", target_file);
	close(fd);
	return (0);
}
