/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 15:30:56 by seyu              #+#    #+#             */
/*   Updated: 2021/07/02 02:03:24 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "pipex_utils.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	idx;

	if (!s)
		return ;
	idx = 0;
	while (s[idx])
		idx += 1;
	write(fd, s, idx);
}
