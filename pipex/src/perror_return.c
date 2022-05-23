/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perror_return.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 23:11:12 by seyu              #+#    #+#             */
/*   Updated: 2021/07/02 15:19:21 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "pipex.h"
#include "pipex_utils.h"

int	perror_int(const char *str)
{
	perror(str);
	return (-1);
}

void
	*perror_ptr(const char *str)
{
	perror(str);
	return (NULL);
}

int	print_usage(void)
{
	ft_putendl_fd("Usage: ./pipex file1 cmd1 cmd2 file2", 2);
	return (1);
}
