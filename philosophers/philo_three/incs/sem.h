/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 15:27:50 by seyu              #+#    #+#             */
/*   Updated: 2021/03/14 03:02:09 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEM_H
# define SEM_H

# include <semaphore.h>

# include "options.h"

# define STOP_SEM_NAME "stop"
# define FULL_SEM_NAME "full"
# define PRINT_SEM_NAME "print"
# define START_SEM_NAME "start"

sem_t		**stop_sem(void);
sem_t		**full_sem(void);
sem_t		**print_sem(void);
sem_t		**start_sem(void);

int			init_sem(void);
int			clear_sem(void);

#endif
