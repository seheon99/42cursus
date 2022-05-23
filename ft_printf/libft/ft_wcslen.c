/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcslen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 17:13:27 by seyu              #+#    #+#             */
/*   Updated: 2020/07/19 17:14:11 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>

int	ft_wcslen(const wchar_t *wcs)
{
	int	len;

	len = 0;
	while (wcs[len])
		len += 1;
	return (len);
}
