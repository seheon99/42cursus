/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:13:18 by seyu              #+#    #+#             */
/*   Updated: 2021/03/24 04:40:19 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

#include <ctime>

ZombieHorde::ZombieHorde(int num_of_zombies)
{
	std::string	type_pool[] = {
		"Defense", "Charge", "Ambush", "Bomber",
		"Magic", "Support", "Healing", "Ranged"
	};
	std::string	name_pool[] = {
		"Licorice Cookie",
		"Dark Choco Cookie",
		"Latte Cookie",
		"Milk Cookie",
		"Herb Cookie",
		"Pomegranate Cookie",
		"Espresso Cookie",
		"Adventure Cookie",
	};

	std::srand(std::time(0));
	this->num_of_zombies = num_of_zombies;
	zombies = new Zombie[num_of_zombies];
	for (int itr = 0; itr < num_of_zombies; itr++)
	{
		zombies[itr].set_type(type_pool[std::rand() % 8]);
		zombies[itr].set_name(name_pool[std::rand() % 8]);
	}
}

ZombieHorde::~ZombieHorde()
{
	delete[] (zombies);
}

int	ZombieHorde::announce()
{
	for (int itr = 0; itr < num_of_zombies; itr++)
		zombies[itr].announce();
	return (0);
}
