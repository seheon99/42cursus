/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 06:32:26 by seyu              #+#    #+#             */
/*   Updated: 2021/03/12 03:23:57 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

unsigned long	g_time_base;

int	set_timebase(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	g_time_base = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (0);
}

int	get_timestamp(void)
{
	struct timeval		tv;
	unsigned long long	current_time;

	gettimeofday(&tv, NULL);
	current_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (current_time - g_time_base);
}

int	msleep(unsigned long milliseconds)
{
	unsigned long	base_timestamp;
	unsigned long	current_timestamp;
	long			left_time;

	base_timestamp = get_timestamp();
	while (TRUE)
	{
		current_timestamp = get_timestamp();
		left_time = milliseconds - (current_timestamp - base_timestamp);
		if (left_time < 0)
			return (0);
		usleep(left_time * 500);
	}
	return (1);
}
