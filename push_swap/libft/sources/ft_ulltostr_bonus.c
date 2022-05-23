/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltostr_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 20:22:41 by seyu              #+#    #+#             */
/*   Updated: 2021/05/01 19:05:42 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_ulltostr(unsigned long long int n, char *numstr, char *base_str)
{
	int		base;
	int		size;

	if (!numstr || !base_str)
		return (0);
	base = ft_strlen(base_str);
	if (base < 2)
		return (0);
	size = ft_intlogn(n, base) + 1;
	numstr = malloc(sizeof(char) * (size + 1));
	numstr[size--] = '\0';
	while (size >= 0)
	{
		numstr[size--] = base_str[n % base];
		n /= base;
	}
	return (numstr);
}
