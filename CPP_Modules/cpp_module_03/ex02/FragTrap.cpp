/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 04:25:44 by seyu              #+#    #+#             */
/*   Updated: 2021/04/05 02:56:16 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "FragTrap.hpp"

#define RANDOM_SELECT(VAL, TYPE) (VAL[std::rand() % (sizeof(VAL) / sizeof(TYPE))])

FragTrap::FragTrap(std::string name) : ClapTrap(100, 100, 100, 100, 1, name, 30, 20, 5)
{
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const& obj)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = obj;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap&
	FragTrap::operator=(FragTrap const& other)
{
	ClapTrap::operator=(other);
	return (*this);
}

unsigned int
	FragTrap::vaulthunter_dot_exe(std::string const& target)
{
	static const std::string	skill_pool[] = {
		"Clap-In-The-Box",
		"Gun Wizard",
		"Torgue Flesta",
		"Pirate Ship Mode",
		"One Shot Wonder",
		"Laser Inferno",
		"Miniontrap",
		"Meat Unicycle",
		"Funzerker",
		"Mechromagician",
		"Shhhh... Trap!",
		"Blight Bot",
		"Rubber Ducky",
		"Senseless Sacrifice",
		"Medbot",
	};

	if (_energyPoints < 25)
	{
		std::cout << _name << " is not enough energy to execute VaultHunter.EXE." << std::endl;
		return (_energyPoints);
	}
	std::cout << _name << " used " << RANDOM_SELECT(skill_pool, std::string) << " skill to " << target << "!" << std::endl;
	return (_energyPoints -= 25);
}
