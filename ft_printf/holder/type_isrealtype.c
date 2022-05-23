/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_isrealtype.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 09:50:39 by seyu              #+#    #+#             */
/*   Updated: 2020/07/15 09:54:01 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	int
**	type_isrealtype()
**	Check the conversion specifier
**			is for real type (e, E, f, F, g, G)
**	@param	const int	type:	conversion specifier
**	@return	int	0:	false, not for real type nor invalid conversion specifier
**				1:	true, valid conversion specifier for real type
*/

int	type_isrealtype(const int type)
{
	return (type == 'e' || type == 'E'
			|| type == 'f' || type == 'F' || type == 'g' || type == 'G');
}
