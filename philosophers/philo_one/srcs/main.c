/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 05:35:54 by seyu              #+#    #+#             */
/*   Updated: 2021/03/14 02:46:52 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

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
	init_log();
	init_philo_life();
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
	clear_log();
	return (0);
}

int	main(int argc, char **argv)
{
	if (parse_options(argc, argv) != 0)
		return (1);
	run_simulation();
	return (0);
}
