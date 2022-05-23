/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:26:48 by seyu              #+#    #+#             */
/*   Updated: 2021/05/21 03:57:22 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structure.h"

int	push_stack(t_stack *stack, void *data)
{
	void	**new_data;
	int		itr;

	if (stack->size == stack->capacity)
	{
		new_data = ft_calloc(stack->capacity * 2, sizeof(void *));
		itr = -1;
		while (++itr < stack->capacity)
			new_data[itr] = stack->data[itr];
		stack->capacity *= 2;
		free(stack->data);
		stack->data = new_data;
	}
	stack->data[stack->size++] = data;
	return (stack->size);
}

int	pop_stack(t_stack *stack, void **data)
{
	if (stack->size <= 0)
		return (FALSE);
	if (data != NULL)
		*data = stack->data[stack->size];
	stack->size -= 1;
	return (stack->size);
}
