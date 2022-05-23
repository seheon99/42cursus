/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_holder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 09:33:56 by seyu              #+#    #+#             */
/*   Updated: 2020/10/27 21:26:51 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <wchar.h>

#include "holder.h"
#include "write.h"

int	write_holder(t_holder *holder)
{
	if (type_isinttype(holder->type))
		return (write_inttype(holder));
	else if (type_ischartype(holder->type))
		return (write_chartype(holder));
	else if (type_isstrtype(holder->type))
		return (write_strtype(holder));
	return (0);
}
