/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 05:35:54 by seyu              #+#    #+#             */
/*   Updated: 2021/03/14 02:47:16 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

const char	*g_log_string[] = {
	"has taken a fork",
	"is eating",
	"is sleeping",
	"is thinking",
	"died",
};

t_options
	*option(void)
{
	static t_options	option_;

	return (&option_);
}

int	*stopped(void)
{
	static int	stopped_ = FALSE;

	return (&stopped_);
}

static int
	print_log(t_log *log)
{
	static int	count_full_philo = 0;

	if (log->status == S_FULL)
	{
		if (++count_full_philo == option()->num_of_philo)
		{
			printf("==================================================\n");
			printf("        All philosophers have eaten enough\n");
			printf("                Stop simulation\n");
			printf("==================================================\n");
			*stopped() = TRUE;
		}
	}
	else
	{
		printf("%7d %3d %s\n",
				log->timestamp, log->philo_no, g_log_string[log->status]);
		if (log->status == S_DIE)
			*stopped() = TRUE;
	}
	return (0);
}

static int
	run_simulation(void)
{
	t_log	*log;

	*stopped() = FALSE;
	if (init_philo_life() == 1 || init_log() == 1)
	{
		clear_philo_life();
		clear_log();
		perror("errno");
		return (1);
	}
	set_timebase();
	start_philos();
	while (*stopped() == FALSE)
	{
		if ((log = pop_log()) == NULL)
			continue ;
		print_log(log);
		free(log);
	}
	stop_philos();
	clear_philo_life();
	clear_log();
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
