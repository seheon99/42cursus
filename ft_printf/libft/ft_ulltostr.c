/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltostr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 15:32:01 by seyu              #+#    #+#             */
/*   Updated: 2020/07/25 19:04:36 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ulltostr_get_numsize(unsigned long long int numb, int base)
{
	size_t	rtn;

	rtn = 0;
	while (numb > 0)
	{
		rtn += 1;
		numb /= base;
	}
	return (rtn);
}

char		*ft_ulltostr(unsigned long long int n,
				int prec,
				char *numstr,
				const char *base_str)
{
	int	base;
	int	size;

	if (!base_str || (base = ft_strlen(base_str)) < 2)
		return (0);
	size = ulltostr_get_numsize(n, base);
	prec = ft_llmax(prec - size, 0);
	if (!numstr && !(numstr = malloc(sizeof(char) * (size + 1))))
		return (0);
	numstr[size + prec] = '\0';
	while (size > 0)
	{
		numstr[--size + prec] = base_str[n % base];
		n /= base;
	}
	while (prec > 0)
		numstr[--prec] = base_str[0];
	return (numstr);
}
