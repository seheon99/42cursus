/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_isstrtype.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 12:26:31 by seyu              #+#    #+#             */
/*   Updated: 2020/07/15 12:27:15 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	int
**	type_isstrtype()
**	Check the conversion specifier
**			is for string type (s, S)
**	@param	const int	type:	conversion specifier
**	@return	int	0:	false, not for character or string type
**							nor invalid conversion specifier
**				1:	true, valid conversion specifier
**							for character or string type
*/

int	type_isstrtype(const int type)
{
	return (type == 's' || type == 'S');
}
