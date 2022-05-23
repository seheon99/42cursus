/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 00:41:26 by seyu              #+#    #+#             */
/*   Updated: 2021/02/01 18:56:25 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parse_line(const char *line)
{
	t_proc	*target_proc;
	int		last_bytes;

	ft_lstadd_back(process_list(), ft_lstnew(new_process(NOPIPE)));
	target_proc = ft_lstlast(*process_list())->content;
	last_bytes = 0;
	while (last_bytes >= 0 && *(line += last_bytes) != '\0')
	{
		while (*line == ' ')
			line++;
		if (*line == '>' || *line == '<')
			last_bytes = parse_redirect(line, target_proc->fd);
		else if (*line == ';' || *line == '|')
			last_bytes = parse_separator(line, &target_proc);
		else if ((last_bytes = read_token(line)) > 0)
			ft_lstadd_back(&(target_proc->arg_list), ft_lstnew(
				is_buffer_empty() == TRUE ? ft_strdup("") : pop_buffer()));
	}
	if (last_bytes < 0)
		ft_lstclear(process_list(), free_process);
	else if (target_proc->arg_list == NULL)
		ft_lstdel_last(process_list(), free_process);
	return (last_bytes < 0 ? -1 : 0);
}
