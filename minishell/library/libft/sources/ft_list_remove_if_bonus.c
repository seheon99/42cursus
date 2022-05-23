/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 01:32:39 by seyu              #+#    #+#             */
/*   Updated: 2020/12/25 02:45:07 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

void
	ft_list_remove_if(
		t_list **lstptr,
		void *data_ref,
		int (*cmp)(void *, void *),
		void (*free_fct)(void *))
{
	t_list	*next_lst;

	if (!lstptr || !cmp || !free_fct)
		return ;
	while (*lstptr)
	{
		if (cmp((*lstptr)->content, data_ref) == 0)
		{
			next_lst = (*lstptr)->next;
			free_fct((*lstptr)->content);
			free(*lstptr);
			*lstptr = next_lst;
		}
		else
			lstptr = &((*lstptr)->next);
	}
}
