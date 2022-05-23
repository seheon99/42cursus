/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 12:16:34 by seyu              #+#    #+#             */
/*   Updated: 2021/03/11 03:39:33 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

/*
**	string.h
**
**	void	*memset(void *, int, size_t)
*/

# include <string.h>

/*
**	stdio.h
**
**	int	printf(char *, ...)
*/

# include <stdio.h>

/*
**	stdlib.h
**
**	int	malloc()
**	int	free()
*/

# include <stdlib.h>

/*
**	unistd.h
**
**	int	write(int, void *, int);
**	int	usleep(useconds_t usec);
*/

# include <unistd.h>

/*
**	sys/time.h
**
**	int	gettimeofday(struct timeval *, NULL)
*/

# include <sys/time.h>

/*
**	pthread.h
**
**	int	pthread_create(pthread_t *, NULL, (void *)()(void *), void *)
**	int	pthread_detach(pthread_t)
**	int	pthread_join(pthread_t, void **)
**	int	pthread_mutex_init()
**	int	pthread_mutex_destroy()
**	int	pthread_mutex_lock()
**	int	pthread_mutex_unlock()
*/

# include <pthread.h>

# include "options.h"
# include "log.h"
# include "philo.h"
# include "utils.h"

int	*stopped(void);

#endif
