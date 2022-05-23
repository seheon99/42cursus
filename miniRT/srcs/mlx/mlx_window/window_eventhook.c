/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_eventhook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:02:14 by seyu              #+#    #+#             */
/*   Updated: 2020/11/02 19:53:39 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/ft_printf.h"

#include "mlx/mlx_window.h"
#include "mlx/mlx_image.h"

int	window_keypress(int keycode, t_window **win)
{
	if (keycode == KEYCODE_ESC)
		window_delete(win);
	else if (keycode == KEYCODE_SPACE)
		window_put_next_image(*win);
	return (0);
}
