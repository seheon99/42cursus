/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 11:03:15 by seyu              #+#    #+#             */
/*   Updated: 2021/05/20 11:09:27 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structure.h"

int	last_data_stack(t_stack *stack, void **data)
{
	if (stack->size == 0)
		return (FALSE);
	if (data != NULL)
		*data = stack->data[stack->size - 1];
	return (TRUE);
}
