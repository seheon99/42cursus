/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 03:03:42 by seyu              #+#    #+#             */
/*   Updated: 2021/03/11 04:19:24 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static int
	parse_intstr(const char *str)
{
	int	rtn;
	int	itr;

	rtn = 0;
	itr = -1;
	while (str[++itr] != '\0')
	{
		if (str[itr] < '0' || str[itr] > '9')
			return (-1);
		rtn *= 10;
		rtn += str[itr] - '0';
	}
	return (rtn);
}

int	parse_options(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf("Error: Please enter the required options\n");
		return (1);
	}
	if ((option()->num_of_philo = parse_intstr(argv[1])) == -1 ||
			(option()->time_to_die = parse_intstr(argv[2])) == -1 ||
			(option()->time_to_eat = parse_intstr(argv[3])) == -1 ||
			(option()->time_to_sleep = parse_intstr(argv[4])) == -1 ||
			(argc == 6 &&
					(option()->num_of_quota = parse_intstr(argv[5])) == -1))
	{
		printf("Error: Invalid non-numeric argument\n");
		return (1);
	}
	if (argc == 5)
		option()->num_of_quota = -1;
	return (0);
}
