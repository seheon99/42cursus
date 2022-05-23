/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 18:47:50 by seyu              #+#    #+#             */
/*   Updated: 2021/05/24 02:41:36 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "libft.h"

# include "game.h"
# include "instructions.h"

# include "data_structure.h"

# define SPECIAL_SIZE 		5
# define SPECIAL_QUICK_SIZE	3

# define ASCENDING	2
# define DESCENDING	1

int				is_sorted(t_queue *target_queue, int target, int size);

struct			s_sort
{
	t_game		*game;
	int			target;
	int			size;
};
typedef struct s_sort			t_sort;

int				quick_sort(t_sort *sort);
int				special_quick_sort(t_sort *sort);
int				find_pivot(t_sort *sort, \
						int *big_pivot, int *small_pivot, int order);
int				number_of_unsorted(t_sort *sort);

struct			s_answer_list
{
	t_queue					*data;
	t_queue					*answer;
	struct s_answer_list	*next;
};
typedef struct s_answer_list	t_answer_list;

t_answer_list	*new_list(t_queue *data, t_queue *answer);
t_answer_list	*copy_list(t_answer_list *list);
void			remove_all_list(t_answer_list **head);
void			append_list(t_answer_list **list, int inst);

int				special_sort(t_sort *sort);

#endif
