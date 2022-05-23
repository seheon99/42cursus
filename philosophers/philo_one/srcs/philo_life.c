/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 14:55:11 by seyu              #+#    #+#             */
/*   Updated: 2021/03/12 02:25:44 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

pthread_mutex_t	*g_forks;

static int
	pick_up_fork(int philo_no)
{
	int	fork_no[2];
	int	num_of_philo;

	num_of_philo = option()->num_of_philo;
	fork_no[0] = (philo_no - 1 + num_of_philo - 1) % num_of_philo;
	fork_no[1] = philo_no - 1;
	pthread_mutex_lock(g_forks + fork_no[philo_no % 2 == 1 ? 1 : 0]);
	push_log(philo_no, S_FORK);
	pthread_mutex_lock(g_forks + fork_no[philo_no % 2 == 1 ? 0 : 1]);
	push_log(philo_no, S_FORK);
	return (0);
}

static int
	put_down_fork(int philo_no)
{
	int	fork_no[2];
	int	num_of_philo;

	num_of_philo = option()->num_of_philo;
	fork_no[0] = (philo_no - 1 + num_of_philo - 1) % num_of_philo;
	fork_no[1] = philo_no - 1;
	pthread_mutex_unlock(g_forks + fork_no[0]);
	pthread_mutex_unlock(g_forks + fork_no[1]);
	return (0);
}

void
	*philo_life(void *philo_addr)
{
	t_philo	*philo;

	philo = philo_addr;
	summon_killer(philo);
	while (*stopped() == FALSE)
	{
		pick_up_fork(philo->no);
		push_log(philo->no, S_EAT);
		if (++(philo->eat_count) == option()->num_of_quota)
			push_log(philo->no, S_FULL);
		summon_killer(philo);
		msleep(option()->time_to_eat);
		push_log(philo->no, S_SLEEP);
		put_down_fork(philo->no);
		msleep(option()->time_to_sleep);
		push_log(philo->no, S_THINK);
	}
	free(philo_addr);
	return (0);
}

int	init_philo_life(void)
{
	int	itr;

	g_forks = malloc(sizeof(pthread_mutex_t) * option()->num_of_philo);
	itr = -1;
	while (++itr < option()->num_of_philo)
		pthread_mutex_init(g_forks + itr, NULL);
	return (0);
}

int	clear_philo_life(void)
{
	int	itr;

	itr = -1;
	while (++itr < option()->num_of_philo)
		pthread_mutex_destroy(g_forks + itr);
	free(g_forks);
	return (0);
}
