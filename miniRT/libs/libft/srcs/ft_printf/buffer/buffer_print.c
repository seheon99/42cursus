/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 15:03:51 by seyu              #+#    #+#             */
/*   Updated: 2020/07/19 16:33:26 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "buffer.h"

int	buffer_print(t_buffer **buf)
{
	int	size;

	size = write(1, (*buf)->buf, (*buf)->size);
	delete_buffer(buf);
	return (size);
}
