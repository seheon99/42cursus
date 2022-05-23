/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 05:23:18 by seyu              #+#    #+#             */
/*   Updated: 2021/03/24 05:33:45 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

#include <iostream>

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{}

void
	HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}

void
	HumanB::attack()
{
	std::cout << _name << " attacks with his " << _weapon->getType() << std::endl;
}
