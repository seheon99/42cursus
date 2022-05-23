/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:52:30 by seyu              #+#    #+#             */
/*   Updated: 2020/11/02 19:53:35 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/ft_printf.h"

int	error_unimplemented_event(char *event_name)
{
	ft_printf("%s does not implemented.\n", event_name);
	return (0);
}
