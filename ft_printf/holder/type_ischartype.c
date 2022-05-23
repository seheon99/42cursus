/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_ischartype.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 09:54:15 by seyu              #+#    #+#             */
/*   Updated: 2020/07/19 20:21:52 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	int
**	type_ischartype()
**	Check the conversion specifier
**			is for character type (c, C)
**	@param	const int	type:	conversion specifier
**	@return	int	0:	false, not for character or string type
**							nor invalid conversion specifier
**				1:	true, valid conversion specifier
**							for character or string type
*/

int	type_ischartype(const int type)
{
	return (type == 'c' || type == 'C' || type == '%');
}
