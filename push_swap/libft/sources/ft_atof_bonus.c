/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:23:30 by seyu              #+#    #+#             */
/*   Updated: 2021/05/01 19:14:39 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int
	get_start_idx(const char *nptr, int *signbit)
{
	int	idx;

	idx = 0;
	while (ft_isspace(nptr[idx]))
		idx += 1;
	if (signbit)
		*signbit = (nptr[idx] == '-');
	if (nptr[idx] == '+' || nptr[idx] == '-')
		idx += 1;
	return (idx);
}

double
	ft_atof(const char *nptr)
{
	int		signbit;
	int		idx;
	double	value;
	double	degree;

	idx = get_start_idx(nptr, &signbit);
	value = 0;
	while (ft_isdigit(nptr[idx]))
	{
		value *= 10;
		value += nptr[idx++] - '0';
	}
	if (nptr[idx++] != '.' && signbit)
		return (-value);
	else if (nptr[idx - 1] != '.' && !signbit)
		return (value);
	degree = 1;
	while (ft_isdigit(nptr[idx]))
	{
		degree /= 10;
		value += degree * (nptr[idx++] - '0');
	}
	if (signbit)
		return (-value);
	return (value);
}
