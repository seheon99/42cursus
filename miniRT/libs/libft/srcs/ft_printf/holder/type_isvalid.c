/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_isvalid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 09:36:59 by seyu              #+#    #+#             */
/*   Updated: 2020/07/19 20:22:06 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "holder.h"

int	type_isvalid(const int type)
{
	if (type_isinttype(type))
		return (1);
	else if (type_isrealtype(type))
		return (1);
	else if (type_ischartype(type))
		return (1);
	else if (type_isstrtype(type))
		return (1);
	return (0);
}
