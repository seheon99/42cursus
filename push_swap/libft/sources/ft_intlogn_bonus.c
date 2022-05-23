/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlogn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 20:16:51 by seyu              #+#    #+#             */
/*   Updated: 2020/06/09 20:43:21 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_intlogn(size_t numb, int base)
{
	int	rtn;

	rtn = 0;
	while (numb / base >= 1)
	{
		rtn += 1;
		numb /= base;
	}
	return (rtn);
}
