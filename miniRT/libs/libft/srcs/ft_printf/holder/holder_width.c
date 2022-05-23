/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   holder_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 10:18:27 by seyu              #+#    #+#             */
/*   Updated: 2020/10/27 21:26:36 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "holder.h"

int	holder_width(const char *widthpart,
			int *width,
			va_list *ap)
{
	int	itr;

	if (width)
		*width = 0;
	itr = 0;
	if (!width || !widthpart[itr])
		return (itr);
	if (widthpart[itr] == '*')
	{
		*width = va_arg(*ap, int);
		itr += 1;
	}
	else
	{
		*width = ft_atoi(widthpart);
		while (ft_isdigit(widthpart[itr]))
			itr += 1;
	}
	return (itr);
}
