/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 02:05:37 by seyu              #+#    #+#             */
/*   Updated: 2021/03/14 02:35:54 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int	init_sem(void)
{
	sem_unlink(STOP_SEM_NAME);
	*stop_sem() = sem_open(STOP_SEM_NAME, O_CREAT | O_EXCL, 0755, 0);
	sem_unlink(FULL_SEM_NAME);
	*full_sem() = sem_open(FULL_SEM_NAME, O_CREAT | O_EXCL, 0755, 0);
	sem_unlink(PRINT_SEM_NAME);
	*print_sem() = sem_open(PRINT_SEM_NAME, O_CREAT | O_EXCL, 0755, 1);
	sem_unlink(START_SEM_NAME);
	*start_sem() = sem_open(START_SEM_NAME, O_CREAT | O_EXCL, 0755, 0);
	return (0);
}

int	clear_sem(void)
{
	sem_close(*full_sem());
	sem_unlink(FULL_SEM_NAME);
	sem_close(*stop_sem());
	sem_unlink(STOP_SEM_NAME);
	sem_close(*print_sem());
	sem_unlink(PRINT_SEM_NAME);
	sem_close(*start_sem());
	sem_unlink(START_SEM_NAME);
	return (0);
}
