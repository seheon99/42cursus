/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 20:47:09 by seyu              #+#    #+#             */
/*   Updated: 2020/10/27 21:09:49 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <wchar.h>

int			pf_convert_unicode_to_utf8(unsigned int unicode, char utf8[4]);
int			pf_wcslen(const wchar_t *str);

#endif
