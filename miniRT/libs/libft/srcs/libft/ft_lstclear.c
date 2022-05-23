/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 16:10:30 by seyu              #+#    #+#             */
/*   Updated: 2020/04/29 04:38:02 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	if (!del)
		return ;
	while (*lst)
	{
		del((*lst)->content);
		(*lst)->content = NULL;
		next = (*lst)->next;
		(*lst)->next = NULL;
		free(*lst);
		*lst = next;
	}
	*lst = NULL;
}
