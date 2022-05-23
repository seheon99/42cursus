/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 04:13:15 by seyu              #+#    #+#             */
/*   Updated: 2021/03/14 01:41:54 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

const char	*g_log_string[] = {
	"has taken a fork",
	"is eating",
	"is sleeping",
	"is thinking",
	"died",
};

static void
	*print_loop(void *log_addr)
{
	int	timestamp;
	int	philo_no;
	int status;

	timestamp = ((t_log *)(log_addr))->timestamp;
	philo_no = ((t_log *)(log_addr))->philo_no;
	status = ((t_log *)(log_addr))->status;
	free(log_addr);
	sem_wait(*print_sem());
	if (status == S_FULL)
		sem_post(*full_sem());
	else
	{
		printf("%7d %3d %s\n", timestamp, philo_no, g_log_string[status]);
		if (status == S_DIE)
		{
			sem_post(*stop_sem());
			return (NULL);
		}
	}
	sem_post(*print_sem());
	return (NULL);
}

int	print_log(int philo_no, int state)
{
	pthread_t	print_thread;
	t_log		*log;

	log = malloc(sizeof(t_log));
	log->timestamp = get_timestamp();
	log->philo_no = philo_no;
	log->status = state;
	pthread_create(&print_thread, NULL, print_loop, log);
	pthread_detach(print_thread);
	return (0);
}
