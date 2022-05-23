/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 20:41:23 by seyu              #+#    #+#             */
/*   Updated: 2021/12/21 21:26:52 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	unsigned int	integer;
	int				minus;
	size_t			itr;

	integer = 0;
	itr = 0;
	while (ft_isspace(nptr[itr]))
		itr++;
	minus = (nptr[itr] == '-');
	if (nptr[itr] == '+' || nptr[itr] == '-')
		itr++;
	while (ft_isdigit(nptr[itr]))
		integer = integer * 10 + (nptr[itr++] - '0');
	if (integer - (int)integer != 0)
		return (minus ? INT_MIN : INT_MAX);
	return (minus ? -1 * integer : integer);
}
