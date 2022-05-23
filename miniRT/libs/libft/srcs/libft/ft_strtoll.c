/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 16:32:08 by seyu              #+#    #+#             */
/*   Updated: 2020/04/28 19:19:31 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_start_idx(const char *nptr, int *is_minus)
{
	size_t	idx;

	idx = 0;
	while (ft_isspace(nptr[idx]))
		idx += 1;
	if (is_minus)
		*is_minus = (nptr[idx] == '-');
	if (nptr[idx] == '+' || nptr[idx] == '-')
		idx += 1;
	return (idx);
}

static int		get_char_value(const int c)
{
	if (ft_isdigit(c))
		return (c - '0');
	if (ft_isupper(c))
		return (c - 'A' + 10);
	if (ft_islower(c))
		return (c - 'a' + 10);
	return (-1);
}

static int		valid_char(const int c, int base)
{
	int	value;

	value = get_char_value(c);
	return (value >= 0 && value < base);
}

static size_t	get_end_idx(const char *nptr, int base)
{
	size_t idx;

	idx = get_start_idx(nptr, NULL);
	if (nptr[idx] == '+' || nptr[idx] == '-')
		idx += 1;
	if (base == 2 && nptr[idx] == '0' && nptr[idx + 1] == 'b')
		idx += 2;
	if (base == 8 && nptr[idx] == '0')
		idx += 1;
	if (base == 16 && nptr[idx] == '0' && nptr[idx + 1] == 'x')
		idx += 2;
	while (valid_char(nptr[idx], base))
		idx += 1;
	return (idx);
}

long long		ft_strtoll(const char *nptr, const char **endptr, int base)
{
	size_t	idx;
	size_t	end_idx;
	size_t	value;
	int		is_minus;

	if (base < 2 || base > 32)
		return (0);
	idx = get_start_idx(nptr, &is_minus);
	end_idx = get_end_idx(nptr, base);
	value = 0;
	while (valid_char(nptr[idx], base))
	{
		if (value > 0x7fffffffffffffff / 10 && !is_minus)
			return (0x7fffffffffffffff);
		if (value > 0x8000000000000000 / 10 && is_minus)
			return (0x8000000000000000);
		value *= 10;
		value += get_char_value(nptr[idx++]);
	}
	if (endptr)
		*endptr = nptr + end_idx;
	return (is_minus ? -value : value);
}
