/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_alloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:21:54 by seyu              #+#    #+#             */
/*   Updated: 2021/05/19 13:26:07 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structure.h"

t_stack
	*new_stack(void)
{
	t_stack	*stack;

	stack = ft_calloc(1, sizeof(t_stack));
	stack->capacity = INIT_SIZE;
	stack->size = 0;
	stack->data = ft_calloc(INIT_SIZE, sizeof(void *));
	return (stack);
}

void
	delete_stack(t_stack **stack)
{
	free((*stack)->data);
	free(*stack);
	*stack = NULL;
}
