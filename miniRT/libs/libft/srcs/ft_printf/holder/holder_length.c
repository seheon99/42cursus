/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   holder_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 11:27:45 by seyu              #+#    #+#             */
/*   Updated: 2020/07/19 13:53:55 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "holder.h"

static int	length_get_readbytes(const char *lengthpart)
{
	if (lengthpart[0] == 'z' || lengthpart[0] == 'j')
		return (1);
	else if (lengthpart[0] == 'h')
		return (lengthpart[1] == 'h' ? 2 : 1);
	else if (lengthpart[0] == 'l')
		return (lengthpart[1] == 'l' ? 2 : 1);
	return (0);
}

static int	length_get_modifier(const char *lengthpart)
{
	if (lengthpart[0] == 'z')
		return (LENGTH_L);
	else if (lengthpart[0] == 'j')
		return (LENGTH_LL);
	else if (lengthpart[0] == 'h')
		return (lengthpart[1] == 'h' ? LENGTH_HH : LENGTH_H);
	else if (lengthpart[0] == 'l')
		return (lengthpart[1] == 'l' ? LENGTH_LL : LENGTH_L);
	return (NOLENGTH);
}

/*
**	z -> long
**	j -> long long
*/

int			holder_length(const char *lengthpart, int *length)
{
	int	itr;

	itr = 0;
	if (length)
		*length = NOLENGTH;
	if (!length || !lengthpart)
		return (0);
	*length = length_get_modifier(lengthpart);
	return (length_get_readbytes(lengthpart));
}
