/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_buffer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 15:00:23 by seyu              #+#    #+#             */
/*   Updated: 2020/07/19 15:03:13 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "buffer.h"

t_buffer	*new_buffer(int size)
{
	t_buffer	*newbuf;

	newbuf = malloc(sizeof(t_buffer));
	newbuf->buf = malloc(sizeof(char) * (size + 1));
	(newbuf->buf)[size] = '\0';
	newbuf->size = size;
	return (newbuf);
}
