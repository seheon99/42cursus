/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 06:18:09 by seyu              #+#    #+#             */
/*   Updated: 2021/03/14 02:30:43 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

pid_t	*g_philo_pid;

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
	int	pid;

	g_philo_pid = malloc(sizeof(pid_t) * option()->num_of_philo);
	itr = -1;
	while (++itr < option()->num_of_philo)
	{
		if ((pid = fork()) == 0)
		{
			philo_life(new_philo(itr + 1));
			exit(1);
		}
		else
			g_philo_pid[itr] = pid;
	}
	itr = -1;
	while (++itr < option()->num_of_philo)
		sem_post(*start_sem());
	return (0);
}

int	stop_philos(void)
{
	int	itr;

	itr = -1;
	while (++itr < option()->num_of_philo)
		kill(g_philo_pid[itr], SIGTERM);
	free(g_philo_pid);
	return (0);
}
