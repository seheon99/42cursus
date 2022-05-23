/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:13:30 by seyu              #+#    #+#             */
/*   Updated: 2021/03/24 04:30:01 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

int	ZombieEvent::setZombieType(std::string zombie_type)
{
	if (zombie_type.empty() == true)
		return (1);
	this->zombie_type = zombie_type;
	return (0);
}

int	ZombieEvent::randomZombieType(void)
{
	int			type_random;
	std::string	type_pool[] = {
		"Defense", "Charge", "Ambush", "Bomber",
		"Magic", "Support", "Healing", "Ranged"
	};

	type_random = std::rand() % 8;
	this->setZombieType(type_pool[type_random]);
	return (type_random);
}

Zombie*
	ZombieEvent::newZombie(std::string zombie_name)
{
	if (this->zombie_type.empty() == true || zombie_name.empty() == true)
		return (NULL);
	return (new Zombie(this->zombie_type, zombie_name));
}
