/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 15:32:31 by seyu              #+#    #+#             */
/*   Updated: 2021/07/01 21:33:28 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "pipex_utils.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	idx;

	if (!s)
		return ;
	idx = 0;
	while (s[idx])
		write(fd, s + idx++, 1);
	write(fd, "\n", 1);
}
