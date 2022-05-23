/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 16:02:27 by seyu              #+#    #+#             */
/*   Updated: 2021/05/21 00:38:15 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *newlst)
{
	t_list	*last;

	if (!lst || !newlst)
		return ;
	last = *lst;
	while (*lst)
	{
		last = *lst;
		lst = &((*lst)->next);
	}
	*lst = newlst;
	newlst->prev = last;
	newlst->next = NULL;
}
