/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:52:31 by seyu              #+#    #+#             */
/*   Updated: 2021/07/02 16:20:50 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_utils.h"

char	*ft_strchr(const char *str, int character)
{
	return (ft_memchr(str, character, ft_strlen(str) + 1));
}
