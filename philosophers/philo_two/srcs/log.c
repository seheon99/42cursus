/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 11:49:43 by seyu              #+#    #+#             */
/*   Updated: 2021/03/12 03:47:35 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

t_log_tree	*g_log_tree_root;
sem_t		*g_log_tree_sem;

static void
	*push_log_tree(void *log_addr)
{
	t_log_tree	**branch_ptr;
	t_log		*log;

	log = log_addr;
	sem_wait(g_log_tree_sem);
	if (*stopped() == TRUE)
	{
		sem_post(g_log_tree_sem);
		return (NULL);
	}
	branch_ptr = &g_log_tree_root;
	while (*branch_ptr != NULL)
	{
		if ((*branch_ptr)->log->timestamp > log->timestamp)
			branch_ptr = &((*branch_ptr)->left);
		else
			branch_ptr = &((*branch_ptr)->right);
	}
	*branch_ptr = malloc(sizeof(t_log_tree));
	(*branch_ptr)->log = log;
	(*branch_ptr)->left = NULL;
	(*branch_ptr)->right = NULL;
	sem_post(g_log_tree_sem);
	return (NULL);
}

int	push_log(int philo_no, int status)
{
	pthread_t	put_thread;
	t_log		*log;
	int			rtn;

	log = malloc(sizeof(t_log));
	log->timestamp = get_timestamp();
	log->philo_no = philo_no;
	log->status = status;
	if ((rtn = pthread_create(&put_thread, NULL, push_log_tree, log)) > 0)
		return (rtn);
	if ((rtn = pthread_detach(put_thread)) > 0)
		return (rtn);
	return (0);
}

t_log
	*pop_log(void)
{
	t_log_tree	**branch_ptr;
	t_log_tree	*oldest_branch;
	t_log		*log;

	if (g_log_tree_root == NULL)
		return (NULL);
	sem_wait(g_log_tree_sem);
	branch_ptr = &g_log_tree_root;
	while ((*branch_ptr)->left != NULL)
		branch_ptr = &((*branch_ptr)->left);
	oldest_branch = *branch_ptr;
	*branch_ptr = (*branch_ptr)->right;
	sem_post(g_log_tree_sem);
	log = oldest_branch->log;
	free(oldest_branch);
	return (log);
}

int	init_log(void)
{
	sem_unlink(LOG_SEM_NAME);
	g_log_tree_sem = sem_open(LOG_SEM_NAME, O_CREAT | O_EXCL, 0755, 1);
	if (g_log_tree_sem == SEM_FAILED)
	{
		printf("Error: \"%s\" semaphore file already exists\n", LOG_SEM_NAME);
		return (1);
	}
	return (0);
}

int	clear_log(void)
{
	t_log	*log;

	while ((log = pop_log()) != NULL)
		free(log);
	if (g_log_tree_sem != NULL && g_log_tree_sem != SEM_FAILED)
	{
		sem_close(g_log_tree_sem);
		sem_unlink(LOG_SEM_NAME);
	}
	return (0);
}
