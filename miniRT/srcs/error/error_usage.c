/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 01:36:20 by seyu              #+#    #+#             */
/*   Updated: 2020/11/06 17:10:29 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "error.h"
#include "libs/ft_printf.h"

void	error_usage(char *program_name)
{
	ft_printf("Usage: %s [.rt file] [--save]\n", program_name);
	exit(EXIT_FAILURE);
}
