/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_first_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 03:46:40 by seyu              #+#    #+#             */
/*   Updated: 2021/05/21 00:54:10 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	ft_lstdel_first()
**
**	This function free the first element of 'lst'
**		and specifies the next element as the head of 'lst'.
**	This function depend on the function, 'ft_lstdelone()'.
**
**	@param lst: Pointer of the head of the target list
**	@param del: Function to delete content
**	@return void
*/

void
	ft_lstdel_first(t_list **lst, void (*del)(void *))
{
	t_list	*target;

	if (!lst || !*lst)
		return ;
	target = *lst;
	while (target->prev != NULL)
		target = target->prev;
	if (target == *lst)
		*lst = (*lst)->next;
	ft_lstdelone(target, del);
}
