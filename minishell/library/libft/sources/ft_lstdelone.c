/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 16:07:25 by seyu              #+#    #+#             */
/*   Updated: 2020/12/31 09:40:36 by seyu             ###   ########.fr       */
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
	if (!lst || !del)
		return ;
	del(lst->content);
	lst->content = NULL;
	free(lst);
}
