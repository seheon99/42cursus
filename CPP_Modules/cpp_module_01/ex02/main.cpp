/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:29:30 by seyu              #+#    #+#             */
/*   Updated: 2021/03/24 04:43:19 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"

#include <cstdlib>
#include <ctime>

Zombie*
	randomChump(ZombieEvent &ze)
{
	Zombie		*new_zombie;
	std::string	name_pool[] = {
		"Licorice Cookie",
		"Dark Choco Cookie",
		"Latte Cookie",
		"Milk Cookie",
		"Herb Cookie",
		"Pomegranate Cookie",
		"Espresso Cookie",
	};

	new_zombie = ze.newZombie(name_pool[std::rand() % 7]);
	new_zombie->announce();
	return (new_zombie);
}

void
	spawnZombieOnTheHeap(void)
{
	ZombieEvent	ze;

	ze.randomZombieType();
	delete (randomChump(ze));
	delete (randomChump(ze));
}

int	main(void)
{
	std::srand(std::time(0));
	spawnZombieOnTheHeap();
	spawnZombieOnTheHeap();
	spawnZombieOnTheHeap();
	spawnZombieOnTheHeap();
	spawnZombieOnTheHeap();
	system("leaks zombies");
}
