/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_last_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 05:55:08 by seyu              #+#    #+#             */
/*   Updated: 2021/05/21 00:54:24 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
**	ft_lstdel_last()
**
**	This function free the last element of 'lst'
**		and specifies the 'next' pointer of previous element to NULL.
**	This function depend on the function, 'ft_lstdelone()'.
**
**	@param lst: Pointer of the head of the target list
**	@param del: Function to delete content
**	@return void
*/

void
	ft_lstdel_last(t_list **lst, void (*del)(void *))
{
	if (!lst || !*lst)
		return ;
	while ((*lst)->next)
		lst = &((*lst)->next);
	ft_lstdelone(*lst, del);
}
