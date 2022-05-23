/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 17:53:39 by seyu              #+#    #+#             */
/*   Updated: 2020/10/27 21:25:50 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRITE_H
# define WRITE_H

# include <wchar.h>

# include "buffer.h"
# include "holder.h"

int		write_nonholder(const char *format, ssize_t *bytes_read);
int		write_holder(t_holder *holder);

int		write_inttype(t_holder *holder);
int		write_chartype(t_holder *holder);
int		write_strtype(t_holder *holder);

int		inttype_prefixpart(t_holder *holder,
				int prefix_size,
				int data_size,
				t_buffer *buf);
int		inttype_datapart(t_holder *holder,
				int prefix_size,
				int data_size,
				t_buffer *buf);
int		inttype_filling(t_holder *holder,
				int prefix_size,
				int data_size,
				t_buffer *buf);

int		chartype_datapart(t_holder *holder,
				int data_size,
				t_buffer *buf);
int		chartype_filling(t_holder *holder,
				int data_size,
				t_buffer *buf);

int		strtype_datapart(t_holder *holder,
				int data_size,
				t_buffer *buf);
int		strtype_filling(t_holder *holder,
				int data_size,
				t_buffer *buf);

#endif
