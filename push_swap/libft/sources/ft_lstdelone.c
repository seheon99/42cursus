/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 16:07:25 by seyu              #+#    #+#             */
/*   Updated: 2021/05/21 00:52:38 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
**	ft_lstdelone()
**
**	Takes as a parameter an element
**		and frees the memory of the element's content
**		using the function 'del' given as a parameter
**		and free the element.
**	The memory of 'next' must not be freed.
**
**	@param	t_list*			The t_list pointer
**								containing content that will be free
**	@param	void*(void*)	The function to free the content
**	@return	void
*/

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	if (del != NULL)
		del(lst->content);
	if (lst->prev != NULL)
		lst->prev->next = lst->next;
	if (lst->next != NULL)
		lst->next->prev = lst->prev;
	lst->content = NULL;
	free(lst);
}
