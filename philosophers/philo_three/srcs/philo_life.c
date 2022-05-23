/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 14:55:11 by seyu              #+#    #+#             */
/*   Updated: 2021/03/14 02:09:49 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

sem_t	*g_eating_man;
sem_t	*g_forks;

static int
	pick_up_fork(int philo_no)
{
	int	fork_no[2];
	int	num_of_philo;

	sem_wait(g_eating_man);
	num_of_philo = option()->num_of_philo;
	fork_no[0] = (philo_no - 1 + num_of_philo - 1) % num_of_philo;
	fork_no[1] = philo_no - 1;
	sem_wait(g_forks);
	print_log(philo_no, S_FORK);
	sem_wait(g_forks);
	print_log(philo_no, S_FORK);
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
	sem_post(g_forks);
	sem_post(g_forks);
	sem_post(g_eating_man);
	return (0);
}

void
	philo_life(t_philo *philo)
{
	sem_wait(*start_sem());
	set_timebase();
	summon_killer(philo);
	while (TRUE)
	{
		pick_up_fork(philo->no);
		print_log(philo->no, S_EAT);
		if (++(philo->eat_count) == option()->num_of_quota)
			print_log(philo->no, S_FULL);
		summon_killer(philo);
		msleep(option()->time_to_eat);
		print_log(philo->no, S_SLEEP);
		put_down_fork(philo->no);
		msleep(option()->time_to_sleep);
		print_log(philo->no, S_THINK);
	}
	free(philo);
	exit(0);
}

int	init_philo_life(void)
{
	sem_unlink(FORK_SEM_NAME);
	g_forks = sem_open(
			FORK_SEM_NAME, O_CREAT | O_EXCL, 0755, option()->num_of_philo);
	sem_unlink(EAT_SEM_NAME);
	g_eating_man = sem_open(
			EAT_SEM_NAME, O_CREAT | O_EXCL, 0755, option()->num_of_philo / 2);
	if (g_forks == SEM_FAILED || g_eating_man == SEM_FAILED)
	{
		printf("Error: \"%s\" semaphore file already exists\n",
				g_forks == SEM_FAILED ? FORK_SEM_NAME : EAT_SEM_NAME);
		return (1);
	}
	return (0);
}

int	clear_philo_life(void)
{
	if (g_forks != NULL && g_forks != SEM_FAILED)
	{
		sem_close(g_forks);
		sem_unlink(FORK_SEM_NAME);
	}
	if (g_eating_man != NULL && g_eating_man != SEM_FAILED)
	{
		sem_close(g_eating_man);
		sem_unlink(EAT_SEM_NAME);
	}
	return (0);
}
