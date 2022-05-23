/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_array.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 01:53:18 by seyu              #+#    #+#             */
/*   Updated: 2021/01/03 16:17:38 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_ARRAY_H
# define STRING_ARRAY_H

# include "lib/libft.h"
# include "variable.h"

char	**get_argv(t_list *string_list);
char	**get_envp(void);
void	free_string_array(char **string_array);

#endif
