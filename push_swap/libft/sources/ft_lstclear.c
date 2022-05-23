/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 16:10:30 by seyu              #+#    #+#             */
/*   Updated: 2021/05/21 00:48:09 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*target;
	t_list	*next;

	if (lst == NULL || *lst == NULL)
		return ;
	target = *lst;
	while (target->prev != NULL)
		target = target->prev;
	while (target != NULL)
	{
		if (del != NULL)
			del(target->content);
		target->content = NULL;
		target->prev = NULL;
		next = target->next;
		target->next = NULL;
		free(target);
		target = next;
	}
	*lst = NULL;
}
