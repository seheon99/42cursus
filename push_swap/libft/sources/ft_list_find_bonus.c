/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 01:40:45 by seyu              #+#    #+#             */
/*   Updated: 2020/12/25 01:45:35 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list
	*ft_list_find(
		t_list *lstptr,
		void *data_ref,
		int (*cmp)(void *, void *))
{
	if (!cmp)
		return (NULL);
	while (lstptr)
	{
		if (cmp(lstptr->content, data_ref) == 0)
			return (lstptr);
		lstptr = lstptr->next;
	}
	return (NULL);
}
