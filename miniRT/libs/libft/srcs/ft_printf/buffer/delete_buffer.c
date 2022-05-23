/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 15:06:05 by seyu              #+#    #+#             */
/*   Updated: 2020/07/19 15:07:44 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "buffer.h"

void	delete_buffer(t_buffer **buf)
{
	if (!buf)
		return ;
	if ((*buf)->buf)
	{
		free((*buf)->buf);
		(*buf)->buf = NULL;
	}
	free(*buf);
	*buf = NULL;
}
