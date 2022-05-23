/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:20:43 by seyu              #+#    #+#             */
/*   Updated: 2020/11/02 03:51:56 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "utils.h"

/*
**	unsigned short rand()
**
**	This is the pseudo random function, not real random function.
**	The same numbers will be repeated each time the program starts.
**
**	@param	void
**	@return	unsigned short:	New generated random 16 bits number
*/

static unsigned short
	rand(void)
{
	static unsigned short	lfsr = 0xACE1u;
	static unsigned int		bit;

	bit = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5)) & 1;
	return (lfsr = (lfsr >> 1) | (bit << 15));
}

double
	random_double(double min, double max)
{
	unsigned int	random;
	double			random_percent;

	random = rand() << 16 | rand();
	random_percent = (random / (0xFFFFFFFF + 1.0));
	return (min + (max - min) * random_percent);
}

double
	degrees_to_radians(double degrees)
{
	return (degrees * M_PI / 180.0);
}

double
	clamp(double x, double min, double max)
{
	if (x < min)
		return (min);
	else if (x > max)
		return (max);
	else
		return (x);
}
