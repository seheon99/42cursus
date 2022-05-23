/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 22:58:10 by seyu              #+#    #+#             */
/*   Updated: 2020/11/07 04:18:46 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_IMAGE_H
# define MLX_IMAGE_H

# include "mlx_color.h"

struct	s_image
{
	void			*mlx_img;

	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;

	int				width;
	int				height;

	struct s_image	*next_img;
};
typedef	struct s_image	t_image;

struct	s_bmp_file_header
{
	unsigned short	bf_type;
	unsigned int	bf_size;
	unsigned short	bf_reserved1;
	unsigned short	bf_reserved2;
	unsigned int	bf_offbits;
};
typedef	struct s_bmp_file_header	t_bmp_file_header;

struct	s_bmp_info_header
{
	unsigned int	bi_size;
	int				bi_width;
	int				bi_height;
	unsigned short	bi_planes;
	unsigned short	bi_bit_count;
	unsigned int	bi_compression;
	unsigned int	bi_size_image;
	int				bi_x_pels_per_meter;
	int				bi_y_pels_per_meter;
	unsigned int	bi_clr_used;
	unsigned int	bi_clr_important;
};
typedef	struct s_bmp_info_header	t_bmp_info_header;

struct	s_rgb_triple
{
	unsigned char	rgb_alpha;
	unsigned char	rgb_blue;
	unsigned char	rgb_green;
	unsigned char	rgb_red;
};
typedef	struct s_rgb_triple		t_rgb_triple;

int				image_color_scale(t_image *img);
int				image_pixel_put(t_image *img, int x, int y, t_color color);
unsigned int	image_pixel_get(t_image *img, int x, int y);
t_color			image_pixel_get_color(t_image *img, int x, int y);
int				image_print_bmp(t_image *img, char *filepath, char *filename);

#endif
