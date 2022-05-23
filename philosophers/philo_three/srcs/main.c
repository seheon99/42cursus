/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 05:35:54 by seyu              #+#    #+#             */
/*   Updated: 2021/03/14 02:47:08 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static void
	check_everyone_is_full_loop(void)
{
	int	itr;

	itr = -1;
	while (++itr < option()->num_of_philo)
		sem_wait(*full_sem());
	printf("==================================================\n");
	printf("        All philosophers have eaten enough\n");
	printf("                Stop simulation\n");
	printf("==================================================\n");
	sem_post(*stop_sem());
	exit(0);
}

static int
	run_simulation(void)
{
	int	pid;

	init_sem();
	init_philo_life();
	start_philos();
	if ((pid = fork()) == 0)
		check_everyone_is_full_loop();
	sem_wait(*stop_sem());
	kill(pid, SIGTERM);
	stop_philos();
	clear_philo_life();
	clear_sem();
	return (0);
}

int	main(int argc, char **argv)
{
	if (parse_options(argc, argv) != 0)
		return (1);
	if (run_simulation() == 1)
		return (1);
	return (0);
}
