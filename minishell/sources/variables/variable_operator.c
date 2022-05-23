/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_operator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 01:23:33 by seyu              #+#    #+#             */
/*   Updated: 2021/02/01 18:20:33 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "minishell.h"

static int
	cmp_variable_name(void *varptr, void *name_str)
{
	return (ft_strcmp(((t_var *)(varptr))->name, name_str));
}

char
	*get_value_ptr(const char *name)
{
	t_list	*target_elem;

	target_elem =
			ft_list_find(*variable_list(), (void *)name, cmp_variable_name);
	return (target_elem == NULL
					? NULL : ((t_var *)(target_elem->content))->value);
}

int	set_value(const char *name, const char *value)
{
	t_list	*target_elem;
	t_var	*target_content;

	target_elem =
			ft_list_find(*variable_list(), (void *)name, cmp_variable_name);
	if (target_elem == NULL)
	{
		ft_lstadd_back(variable_list(), ft_lstnew(new_variable(name, value)));
		return (1);
	}
	else if (value == NULL)
		return (0);
	else
	{
		target_content = target_elem->content;
		free(target_content->value);
		if (value == NULL)
			target_content->value = NULL;
		else
			target_content->value = ft_strdup(value);
		return (0);
	}
}

int	remove_variable(const char *name)
{
	void	*name_ref;

	name_ref = (void *)name;
	ft_list_remove_if(variable_list(), name_ref, cmp_variable_name, free);
	return (0);
}
