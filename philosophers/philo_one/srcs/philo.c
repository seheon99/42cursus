/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 06:18:09 by seyu              #+#    #+#             */
/*   Updated: 2021/03/14 02:37:28 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static t_philo
	*new_philo(int philo_no)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	philo->no = philo_no;
	philo->state = S_FORK;
	philo->eat_count = 0;
	return (philo);
}

int	start_philos(void)
{
	pthread_t	philo_thread;
	int			itr;

	itr = -1;
	while (++itr < option()->num_of_philo)
	{
		pthread_create(&philo_thread, NULL, philo_life, new_philo(itr + 1));
		pthread_detach(philo_thread);
	}
	return (0);
}

int	stop_philos(void)
{
	clear_philo_life();
	return (0);
}
