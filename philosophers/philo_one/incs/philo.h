/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 05:46:56 by seyu              #+#    #+#             */
/*   Updated: 2021/03/08 16:35:05 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define S_FORK		0
# define S_EAT		1
# define S_SLEEP	2
# define S_THINK	3
# define S_DIE		4
# define S_FULL		5

struct	s_philo
{
	int	no;
	int	state;
	int	eat_count;
};
typedef	struct s_philo	t_philo;

struct	s_killer
{
	t_philo	*target;
	int		last_count;
};
typedef	struct s_killer	t_killer;

int		start_philos(void);
int		stop_philos(void);

void	*philo_life(void *philo_addr);
int		init_philo_life(void);
int		clear_philo_life(void);

int		summon_killer(t_philo *target);

#endif
