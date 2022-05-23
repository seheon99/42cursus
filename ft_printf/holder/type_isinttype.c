/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_isinttype.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 09:40:02 by seyu              #+#    #+#             */
/*   Updated: 2020/07/19 20:01:26 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	int
**	type_isinttype()
**	Check the conversion specifier
**			is for int type (d, i, o, u, x, X, D, O, U)
**	@param	const int	type:	conversion specifier
**	@return	int	0:	false, not for int type nor invalid conversion specifier
**				1:	true, valid conversion specifier for int type
*/

int	type_isinttype(const int type)
{
	return (type == 'd' || type == 'i'
			|| type == 'o' || type == 'u' || type == 'x' || type == 'X'
			|| type == 'D' || type == 'O' || type == 'U' || type == 'p');
}
