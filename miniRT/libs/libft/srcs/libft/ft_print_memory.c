/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 21:01:27 by seyu              #+#    #+#             */
/*   Updated: 2020/04/14 22:00:05 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static char	*g_hex_numbers_char = "0123456789abcdef";

static void	write_addr(int scale, unsigned long long addr)
{
	if (scale == 0)
		return ;
	write_addr(scale - 1, addr / 16);
	write(1, g_hex_numbers_char + addr % 16, 1);
}

static void	write_hex(void *addr, unsigned int size)
{
	int				blank;
	unsigned int	idx;

	idx = -1;
	blank = 0;
	while (++idx < size)
	{
		write(1, g_hex_numbers_char + *(unsigned char *)(addr + idx) / 16, 1);
		write(1, g_hex_numbers_char + *(unsigned char *)(addr + idx) % 16, 1);
		if (blank--)
			write(1, " ", 1);
		else
			blank = 1;
	}
	while (idx++ < 16)
	{
		write(1, "  ", 2);
		if (blank--)
			write(1, " ", 1);
		else
			blank = 1;
	}
}

static void	write_char(char *addr, unsigned int size)
{
	unsigned int idx;

	idx = -1;
	while (++idx < size)
	{
		if (addr[idx] >= 32 && addr[idx] <= 126)
			write(1, addr + idx, 1);
		else
			write(1, ".", 1);
	}
}

void		*ft_print_memory(void *addr, unsigned int size)
{
	while (size > 0)
	{
		write_addr(16, (unsigned long long)addr);
		write(1, ": ", 2);
		write_hex(addr, (size >= 16) ? 16 : size);
		write_char((char *)addr, (size >= 16) ? 16 : size);
		write(1, "\n", 1);
		addr += (size >= 16) ? 16 : size;
		size -= (size >= 16) ? 16 : size;
	}
	return (addr);
}
