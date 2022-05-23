/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltostr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 20:03:55 by seyu              #+#    #+#             */
/*   Updated: 2020/06/12 01:37:05 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_lltostr(long long int numb, char *base_str)
{
	size_t	len;
	char	*numstr;

	if (numb >= 0)
		return (ft_ulltostr(numb, NULL, base_str));
	len = ft_strlen(base_str);
	numstr = malloc(sizeof(char) * (ft_intlogn(-numb, len) + 3));
	numstr[0] = '-';
	ft_ulltostr(-numb, numstr + 1, base_str);
	return (numstr);
}
