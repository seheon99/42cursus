/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 16:07:25 by seyu              #+#    #+#             */
/*   Updated: 2020/11/01 17:17:56 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	ft_lstdelone()
**
**	This functions ONLY free the content that t_list storing,
**		and DOES NOT FREE T_LIST,
**		so YOU HAVE TO FREE T_LIST TO MEMORY LEAK FREE
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
}
