/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 11:19:09 by seyu              #+#    #+#             */
/*   Updated: 2021/01/09 01:43:01 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARIABLE_H
# define VARIABLE_H

struct	s_var
{
	char	*name;
	char	*value;
};
typedef	struct s_var	t_var;

t_list	**variable_list(void);

t_var	*new_variable(const char *name, const char *value);
void	init_variables(const char **envp);

char	*get_value_ptr(const char *name);
int		set_value(const char *name, const char *value);
int		remove_variable(const char *name);

#endif
