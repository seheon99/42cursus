/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 03:06:02 by seyu              #+#    #+#             */
/*   Updated: 2021/01/29 18:45:30 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "minishell.h"

t_list	*g_env_list;

t_list
	**variable_list(void)
{
	static t_list	*var_list;

	return (&var_list);
}

t_var
	*new_variable(const char *name, const char *value)
{
	t_var	*var;

	var = (t_var *)malloc(sizeof(t_var));
	var->name = ft_strdup(name);
	if (value == NULL)
		var->value = NULL;
	else
		var->value = ft_strdup(value);
	return (var);
}

void
	init_variables(const char **envp)
{
	char	**splitted;
	int		itr;

	while (*envp)
	{
		splitted = ft_split(*(envp++), '=');
		ft_lstadd_back(variable_list(),
				ft_lstnew(new_variable(splitted[0], splitted[1])));
		itr = -1;
		while (splitted[++itr])
			free(splitted[itr]);
		free(splitted);
	}
	remove_variable("OLDPWD");
}
