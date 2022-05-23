/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_structure.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:35:57 by seyu              #+#    #+#             */
/*   Updated: 2021/05/22 22:43:10 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_STRUCTURE_H
# define DATA_STRUCTURE_H

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

# define INIT_SIZE 10

# include <stdlib.h>

# include "libft.h"

struct	s_stack
{
	int		capacity;
	int		size;
	void	**data;
};
typedef struct s_stack	t_stack;

t_stack	*new_stack(void);
void	delete_stack(t_stack **stack);

int		push_stack(t_stack *stack, void *data);
int		pop_stack(t_stack *stack, void **data);

int		last_data_stack(t_stack *stack, void **data);

struct	s_queue
{
	int	capacity;
	int	size;
	int	front;
	int	rear;
	int	*data;
};
typedef struct s_queue	t_queue;

t_queue	*new_queue(void);
t_queue	*copy_queue(t_queue *src);
void	delete_queue(t_queue **queue);

int		last_data_queue(t_queue *queue, int *data);
void	append_queue(t_queue *dst, t_queue *src);
void	print_queue(t_queue *q);
void	debug_queue(t_queue *q);
t_queue	*list_to_queue(t_list *list_head);

int		push_queue(t_queue *queue, int data);
int		pop_queue(t_queue *queue, int *data);
int		reverse_push_queue(t_queue *queue, int data);
int		reverse_pop_queue(t_queue *queue, int *data);

int		is_equal_queue(t_queue *q0, t_queue *q1);

void	s_queue(t_queue *queue);
void	p_queue(t_queue *dst, t_queue *src);
void	r_queue(t_queue *queue);
void	rr_queue(t_queue *queue);

#endif
