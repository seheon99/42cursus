/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_one_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 04:55:15 by seyu              #+#    #+#             */
/*   Updated: 2020/12/31 09:41:50 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

/*
**	ft_lstdel_one()
**
**	This function deletes the 'lst' element through the 'del' function
**		and returns the 'next' element.
**	@param: lst = Target element
**	@param: del = Function to delete the data of element
**	@return: t_list* = The next element of the target.
*/

t_list
	*ft_lstdel_one(t_list *lst, void (*del)(void *))
{
	t_list	*next;

	if (!lst || !del)
		return (NULL);
	del(lst->content);
	next = lst->next;
	free(lst);
	return (next);
}
