/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_holder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 12:10:57 by seyu              #+#    #+#             */
/*   Updated: 2020/07/16 20:17:45 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "holder.h"

void	delete_holder(t_holder **holder)
{
	if (!holder)
		return ;
	if ((*holder)->data)
		free((*holder)->data);
	(*holder)->data = NULL;
	free(*holder);
	*holder = NULL;
}
