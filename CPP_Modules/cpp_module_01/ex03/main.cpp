/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 04:37:09 by seyu              #+#    #+#             */
/*   Updated: 2021/03/24 04:42:12 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

int	main(void)
{
	ZombieHorde	*zh = new ZombieHorde(10);

	zh->announce();
	delete (zh);
	system("leaks zombies");
}
