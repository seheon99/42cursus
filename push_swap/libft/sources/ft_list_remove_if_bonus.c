/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 01:32:39 by seyu              #+#    #+#             */
/*   Updated: 2021/05/21 01:19:54 by seyu             ###   ########.fr       */
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
	if (!lstptr || !cmp || !free_fct)
		return ;
	while (*lstptr)
	{
		if (cmp((*lstptr)->content, data_ref) == 0)
			*lstptr = ft_lstdel_one(*lstptr, free_fct);
		else
			lstptr = &((*lstptr)->next);
	}
}
