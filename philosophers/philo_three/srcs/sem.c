/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 15:30:05 by seyu              #+#    #+#             */
/*   Updated: 2021/03/14 02:06:33 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

sem_t
	**stop_sem(void)
{
	static sem_t	*stop_sem_;

	return (&stop_sem_);
}

sem_t
	**full_sem(void)
{
	static sem_t	*full_sem_;

	return (&full_sem_);
}

sem_t
	**print_sem(void)
{
	static sem_t	*print_sem_;

	return (&print_sem_);
}

sem_t
	**start_sem(void)
{
	static sem_t	*start_sem_;

	return (&start_sem_);
}
