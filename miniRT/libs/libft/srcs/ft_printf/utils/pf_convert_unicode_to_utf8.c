/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert_unicode_to_utf8.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 09:52:57 by seyu              #+#    #+#             */
/*   Updated: 2020/10/27 20:48:22 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	utf8_1byte(unsigned int unicode, char utf8[1])
{
	if (!utf8)
		return ;
	utf8[0] = 0b00000000 + (unicode & 0b1111111);
}

static void	utf8_2bytes(unsigned int unicode, char utf8[2])
{
	if (!utf8)
		return ;
	utf8[0] = 0b11000000 + ((unicode >> 6) & 0b11111);
	utf8[1] = 0b10000000 + (unicode & 0b111111);
}

static void	utf8_3bytes(unsigned int unicode, char utf8[3])
{
	if (!utf8)
		return ;
	utf8[0] = 0b11100000 + ((unicode >> 12) & 0b1111);
	utf8[1] = 0b10000000 + ((unicode >> 6) & 0b111111);
	utf8[2] = 0b10000000 + (unicode & 0b111111);
}

static void	utf8_4bytes(unsigned int unicode, char utf8[4])
{
	if (!utf8)
		return ;
	utf8[0] = 0b11110000 + ((unicode >> 18) & 0b111);
	utf8[1] = 0b10000000 + ((unicode >> 12) & 0b111111);
	utf8[2] = 0b10000000 + ((unicode >> 6) & 0b111111);
	utf8[3] = 0b10000000 + (unicode & 0b111111);
}

int			pf_convert_unicode_to_utf8(unsigned int unicode, char utf8[4])
{
	if (unicode >= 0x00d800 && unicode <= 0x00dfff)
		return (0);
	if (unicode >= 0x000000 && unicode <= 0x00007f)
	{
		utf8_1byte(unicode, utf8);
		return (1);
	}
	else if (unicode >= 0x000080 && unicode <= 0x0007ff)
	{
		utf8_2bytes(unicode, utf8);
		return (2);
	}
	else if (unicode >= 0x000800 && unicode <= 0x00ffff)
	{
		utf8_3bytes(unicode, utf8);
		return (3);
	}
	else if (unicode >= 0x010000 && unicode <= 0x10ffff)
	{
		utf8_4bytes(unicode, utf8);
		return (4);
	}
	return (0);
}
