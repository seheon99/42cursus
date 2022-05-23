/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 06:18:09 by seyu              #+#    #+#             */
/*   Updated: 2021/03/14 03:00:17 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

pthread_t	*g_philo_thread;

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
	int	itr;

	g_philo_thread = malloc(sizeof(pthread_t) * option()->num_of_philo);
	itr = 0;
	while (++itr <= option()->num_of_philo)
		pthread_create(g_philo_thread + itr, NULL, philo_life, new_philo(itr));
	return (0);
}

int	stop_philos(void)
{
	int	itr;

	itr = -1;
	while (++itr < option()->num_of_philo)
		pthread_join(g_philo_thread[itr], NULL);
	free(g_philo_thread);
	return (0);
}
