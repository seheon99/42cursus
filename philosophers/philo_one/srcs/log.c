/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 11:49:43 by seyu              #+#    #+#             */
/*   Updated: 2021/03/12 03:47:55 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

t_log_tree		*g_log_tree_root;
pthread_mutex_t	g_log_tree_mutex;
int				g_stop;

int	init_log(void)
{
	int	rtn;

	g_stop = FALSE;
	if ((rtn = pthread_mutex_init(&g_log_tree_mutex, NULL)) > 0)
		return (rtn);
	return (0);
}

static void
	*push_log_tree(void *log_addr)
{
	t_log_tree	**branch_ptr;
	t_log		*log;

	log = log_addr;
	pthread_mutex_lock(&g_log_tree_mutex);
	if (g_stop == TRUE)
	{
		pthread_mutex_unlock(&g_log_tree_mutex);
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
	pthread_mutex_unlock(&g_log_tree_mutex);
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
	pthread_mutex_lock(&g_log_tree_mutex);
	branch_ptr = &g_log_tree_root;
	while ((*branch_ptr)->left != NULL)
		branch_ptr = &((*branch_ptr)->left);
	oldest_branch = *branch_ptr;
	*branch_ptr = (*branch_ptr)->right;
	pthread_mutex_unlock(&g_log_tree_mutex);
	log = oldest_branch->log;
	free(oldest_branch);
	return (log);
}

int	clear_log(void)
{
	int		rtn;
	t_log	*log;

	g_stop = TRUE;
	while ((log = pop_log()) != NULL)
		free(log);
	if ((rtn = pthread_mutex_destroy(&g_log_tree_mutex)) > 0)
		return (rtn);
	return (0);
}
