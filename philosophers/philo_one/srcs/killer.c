/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   killer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 01:38:35 by seyu              #+#    #+#             */
/*   Updated: 2021/03/11 03:22:39 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static t_killer
	*new_killer(t_philo *target, int last_count)
{
	t_killer	*killer;

	killer = malloc(sizeof(t_killer));
	killer->target = target;
	killer->last_count = last_count;
	return (killer);
}

static void
	*watching(void *killer_addr)
{
	t_killer	*killer;

	killer = killer_addr;
	msleep(option()->time_to_die);
	if (*stopped() == TRUE)
		return (NULL);
	if (killer->target->eat_count == killer->last_count)
		push_log(killer->target->no, S_DIE);
	return (NULL);
}

int	summon_killer(t_philo *target)
{
	pthread_t	killer_thread;
	t_killer	*killer;

	killer = new_killer(target, target->eat_count);
	pthread_create(&killer_thread, NULL, watching, killer);
	pthread_detach(killer_thread);
	return (0);
}
