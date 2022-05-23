/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_set_realtype.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 12:22:54 by seyu              #+#    #+#             */
/*   Updated: 2020/07/19 17:04:41 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>

void	*data_set_realtype(va_list *ap)
{
	void	*rtn;

	rtn = malloc(sizeof(double));
	*(double *)rtn = va_arg(*ap, double);
	return (rtn);
}
