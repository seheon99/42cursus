/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 20:32:10 by seyu              #+#    #+#             */
/*   Updated: 2021/02/01 22:36:51 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "minishell.h"

static int
	is_valid_identifier(char *id)
{
	int	itr;

	itr = 0;
	if (id == NULL || (ft_isalpha(id[itr]) != TRUE && id[itr] != '_'))
		return (print_error(ERRNO_INVALID_ID, "export", id, FALSE));
	while (id[++itr] != '\0')
	{
		if (ft_isalnum(id[itr]) != TRUE && id[itr] != '_')
			return (print_error(ERRNO_INVALID_ID, "export", id, FALSE));
	}
	return (TRUE);
}

static int
	get_string(const char *target_string, char **name, char **value)
{
	int	index_equalsign;

	if (ft_strlen(target_string) == 0)
		return (print_error(ERRNO_INVALID_ID, "export", target_string, FALSE));
	index_equalsign = -1;
	while (target_string[++index_equalsign] != '=')
		if (target_string[index_equalsign] == '\0')
			break ;
	*name = ft_strndup(target_string, index_equalsign);
	if (target_string[index_equalsign] == '\0')
		*value = NULL;
	else
		*value = ft_strdup(target_string + index_equalsign + 1);
	return (TRUE);
}

static int
	export_noarg(void)
{
	t_list	*env_elem;
	t_var	*env;

	env_elem = *variable_list();
	while (env_elem != NULL)
	{
		env = env_elem->content;
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(env->name, 1);
		if (env->value)
		{
			ft_putstr_fd("=\"", 1);
			ft_putstr_fd(env->value, 1);
			ft_putstr_fd("\"", 1);
		}
		ft_putendl_fd("", 1);
		env_elem = env_elem->next;
	}
	return (0);
}

int	mini_export(int argc, char **argv)
{
	char	*name;
	char	*value;
	int		itr;
	int		ret;

	if (argc < 1 || !argv || ft_strcmp(argv[0], "export") != 0)
		return (exit_shell(DEBUG_ERROR, "export", NULL, 1));
	if (argc == 1)
		return (export_noarg());
	ret = 0;
	itr = 0;
	while (argv[++itr] != NULL)
	{
		if (get_string(argv[itr], &name, &value) == FALSE)
			continue ;
		if (is_valid_identifier(name) == FALSE)
			ret = 1;
		else
			set_value(name, value);
		free(name);
		free(value);
	}
	return (ret);
}
