/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 06:22:36 by seyu              #+#    #+#             */
/*   Updated: 2021/04/04 07:15:34 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "SuperTrap.hpp"

SuperTrap::SuperTrap(std::string const& name)
		: ClapTrap(name), FragTrap(name), NinjaTrap(name)
{
	std::cout << "SuperTrap default constructor called" << std::endl;
	_hitPoints = 100;
	_hitPointsMax = 100;
	_energyPoints = 120;
	_energyPointsMax = 120;
	_attackDamageMelee = 60;
	_attackDamageRanged = 20;
	_armorDamageReduction = 5;
}

SuperTrap::SuperTrap(SuperTrap const& other)
{
	std::cout << "SuperTrap copy constructor called" << std::endl;
	*this = other;
}

SuperTrap::~SuperTrap()
{
	std::cout << "SuperTrap destructor called" << std::endl;
}

SuperTrap&
	SuperTrap::operator=(SuperTrap const& other)
{
	(ClapTrap)*this = (ClapTrap)other;
	return (*this);
}

unsigned int
	SuperTrap::rangedAttack(std::string const& target)
{
	return (FragTrap::rangedAttack(target));
}

unsigned int
	SuperTrap::meleeAttack(std::string const& target)
{
	return (NinjaTrap::meleeAttack(target));
}
