/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_set_strtype.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 17:01:52 by seyu              #+#    #+#             */
/*   Updated: 2020/10/27 21:26:00 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>

#include "libft.h"
#include "holder.h"

static wchar_t	*strtype_dup_strtowcs(char *src)
{
	wchar_t	*rtn;
	int		itr;
	int		src_len;

	src_len = ft_strlen(src);
	rtn = malloc(sizeof(wchar_t) * (src_len + 1));
	rtn[src_len] = '\0';
	itr = -1;
	while (src[++itr])
		rtn[itr] = src[itr];
	return (rtn);
}

void			*data_set_strtype(va_list *ap, int length)
{
	void	**rtn;

	if (length == LENGTH_L)
	{
		rtn = malloc(sizeof(wchar_t **));
		*(wchar_t **)rtn = va_arg(*ap, wchar_t *);
		if (*rtn == NULL)
			*rtn = strtype_dup_strtowcs("(null)");
	}
	else
	{
		rtn = malloc(sizeof(char **));
		*(char **)rtn = va_arg(*ap, char *);
		if (*rtn == NULL)
			*rtn = ft_strdup("(null)");
	}
	return (rtn);
}
