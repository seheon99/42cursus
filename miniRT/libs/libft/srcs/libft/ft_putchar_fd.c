/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 15:30:03 by seyu              #+#    #+#             */
/*   Updated: 2020/04/14 23:09:13 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_fd(unsigned char c, int fd)
{
	char			unicode[2];

	if (c >= 0x00 && c <= 0x7F)
		write(fd, &c, 1);
	else if (c >= 0xA1 && c <= 0xBF)
	{
		unicode[0] = 0xC2;
		unicode[1] = c;
		write(fd, unicode, 2);
	}
	else if (c >= 0xC0 && c <= 0xFF)
	{
		unicode[0] = 0xC3;
		unicode[1] = c - 0x40;
		write(fd, unicode, 2);
	}
}
