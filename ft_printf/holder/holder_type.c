/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   holder_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 11:59:43 by seyu              #+#    #+#             */
/*   Updated: 2020/07/15 12:03:31 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "holder.h"

int	holder_type(const char *typepart, int *type)
{
	if (type)
		*type = 0;
	if (!type || !typepart)
		return (0);
	if (type_isvalid(typepart[0]))
		*type = typepart[0];
	return (*type ? 1 : 0);
}
