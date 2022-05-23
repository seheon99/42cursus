/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 05:42:03 by seyu              #+#    #+#             */
/*   Updated: 2021/03/12 01:15:21 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOG_H
# define LOG_H

# define LOG_SEM_NAME "/log"

struct	s_log
{
	int	timestamp;
	int	philo_no;
	int	status;
};
typedef	struct s_log	t_log;

struct	s_log_tree
{
	t_log				*log;
	struct s_log_tree	*left;
	struct s_log_tree	*right;
};
typedef	struct s_log_tree	t_log_tree;

int		init_log(void);
int		push_log(int philo_no, int status);
t_log	*pop_log(void);
int		clear_log(void);

#endif
