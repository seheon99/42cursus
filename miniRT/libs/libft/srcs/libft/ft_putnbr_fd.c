/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 15:36:23 by seyu              #+#    #+#             */
/*   Updated: 2020/02/29 00:02:15 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char			*digits;
	unsigned int	n_unsigned;
	long long		top;

	digits = "0123456789";
	n_unsigned = n > 0 ? n : -n;
	if (n < 0)
		write(fd, "-", 1);
	top = 10;
	while (n_unsigned / top > 0)
		top *= 10;
	while (top >= 10)
	{
		write(fd, digits + (n_unsigned % top) / (top / 10), 1);
		top /= 10;
	}
}
