/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 19:36:40 by seyu              #+#    #+#             */
/*   Updated: 2021/01/29 18:51:30 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	mini_env(void)
{
	t_list	*env_elem;
	t_var	*env;

	env_elem = *variable_list();
	while (env_elem != NULL)
	{
		env = env_elem->content;
		if (env->value != NULL)
		{
			ft_putstr_fd(env->name, 1);
			ft_putstr_fd("=", 1);
			ft_putendl_fd(env->value, 1);
		}
		env_elem = env_elem->next;
	}
	return (0);
}
