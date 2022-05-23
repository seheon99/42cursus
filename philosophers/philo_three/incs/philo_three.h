/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 12:16:34 by seyu              #+#    #+#             */
/*   Updated: 2021/03/14 02:05:58 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H

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
**	int		malloc()
**	int		free()
**	void	exit(int status)
*/

# include <stdlib.h>

/*
**	unistd.h
**
**	int		write(int, void *, int)
**	pid_t	fork(void)
**	int		usleep(useconds_t usec)
*/

# include <unistd.h>

/*
**	signal.h
**
**	int	kill(pid_t pid, int sig)
*/

# include <signal.h>
# ifndef SIGTERM
#  define SIGTERM 15
# endif

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

/*
**	semaphore.h
**
**	sem_t	*sem_open(char *, int, mode_t, unsigned int)
**	int		sem_close(sem_t *sem)
**	int		sem_post(sem_t *sem)
**	int		sem_wait(sem_t *sem)
**	int		sem_unlink(const char *)
*/

# include <semaphore.h>

# include "sem.h"
# include "options.h"
# include "philo.h"
# include "utils.h"

#endif
