/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 14:55:12 by seyu              #+#    #+#             */
/*   Updated: 2020/07/19 15:09:39 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_H
# define BUFFER_H

struct		s_buffer
{
	char	*buf;
	int		size;
};
typedef	struct s_buffer	t_buffer;

t_buffer	*new_buffer(int size);
int			buffer_print(t_buffer **buf);
void		delete_buffer(t_buffer **buf);

#endif
