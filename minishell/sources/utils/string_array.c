/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 01:55:16 by seyu              #+#    #+#             */
/*   Updated: 2021/01/26 03:08:00 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "util/string_array.h"

char
	**get_argv(t_list *string_list)
{
	char	**string_array;
	int		itr;

	if (string_list == NULL)
		return (NULL);
	string_array = malloc(sizeof(char *) * (ft_lstsize(string_list) + 1));
	itr = 0;
	while (string_list)
	{
		string_array[itr++] = ft_strdup(string_list->content);
		string_list = string_list->next;
	}
	string_array[itr] = NULL;
	return (string_array);
}

char
	**get_envp(void)
{
	t_list	*lstitr;
	char	**envp;
	char	*tmpstr;
	int		itr;

	envp = malloc(sizeof(char *) * (ft_lstsize(*variable_list()) + 1));
	itr = 0;
	lstitr = *variable_list();
	while (lstitr)
	{
		tmpstr = ft_strjoin(((t_var *)lstitr->content)->name, "=");
		envp[itr++] = ft_strjoin(tmpstr, ((t_var *)lstitr->content)->value);
		free(tmpstr);
		lstitr = lstitr->next;
	}
	envp[itr] = NULL;
	return (envp);
}

void
	free_string_array(char **string_array)
{
	int	itr;

	if (string_array == NULL)
		return ;
	itr = -1;
	while (string_array[++itr])
		free(string_array[itr]);
	free(string_array);
}
