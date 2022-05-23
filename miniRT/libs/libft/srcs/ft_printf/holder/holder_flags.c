/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   holder_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 09:58:55 by seyu              #+#    #+#             */
/*   Updated: 2020/07/16 14:48:23 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "holder.h"

static int	flags_isvalid(const char ch)
{
	if (ch == '#')
		return (FLAG_HASH);
	else if (ch == '-')
		return (FLAG_MINUS);
	else if (ch == '0')
		return (FLAG_ZERO);
	else if (ch == ' ')
		return (FLAG_BLANK);
	else if (ch == '+')
		return (FLAG_PLUS);
	return (0);
}

int			holder_flags(const char *flagspart, int *flags)
{
	int	itr;
	int	flag;

	if (flags)
		*flags = NOFLAGS;
	if (!flags || !flagspart)
		return (0);
	itr = 0;
	while ((flag = flags_isvalid(flagspart[itr])))
	{
		*flags |= flag;
		itr += 1;
	}
	return (itr);
}
