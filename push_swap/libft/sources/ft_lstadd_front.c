/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 15:58:08 by seyu              #+#    #+#             */
/*   Updated: 2021/05/21 00:37:57 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *newlst)
{
	if (!lst || !newlst)
		return ;
	newlst->prev = NULL;
	newlst->next = *lst;
	*lst = newlst;
	(*lst)->prev = newlst;
}
