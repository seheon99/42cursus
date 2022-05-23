/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 13:22:21 by seyu              #+#    #+#             */
/*   Updated: 2021/01/01 13:33:04 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util/print.h"

void
	print_string_list(t_list *lst)
{
	while (lst)
	{
		ft_putchar_fd('\"', 1);
		ft_putstr_fd(lst->content, 1);
		ft_putchar_fd('\"', 1);
		if (lst->next)
			ft_putstr_fd(" -> ", 1);
		lst = lst->next;
	}
	ft_putchar_fd('\n', 1);
}
