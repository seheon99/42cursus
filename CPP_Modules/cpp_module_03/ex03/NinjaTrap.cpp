/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 05:19:37 by seyu              #+#    #+#             */
/*   Updated: 2021/04/04 06:02:53 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(std::string name) : ClapTrap(60, 60, 120, 120, 1, name, 60, 5, 0)
{
	std::cout << "NinjaTrap default constructor called" << std::endl;
}

NinjaTrap::NinjaTrap(NinjaTrap const& obj)
{
	*this = obj;
}

NinjaTrap::~NinjaTrap()
{
	std::cout << "NinjaTrap destructor called" << std::endl;
}

NinjaTrap&
	NinjaTrap::operator=(NinjaTrap const& other)
{
	(ClapTrap)*this = (ClapTrap)other;
	return (*this);
}

unsigned int
	NinjaTrap::ninjaShoebox(ClapTrap& target)
{
	if (_energyPoints < 10)
	{
		std::cout << _name << " is not enough energy to do Ninja Shoebox" << std::endl;
		return (_energyPoints);
	}
	_energyPoints = (_energyPoints > 10 ? _energyPoints - 10 : 0);
	std::cout << _name << " play with ClapTrap" << std::endl;
	target.beRepaired(10);
	return (_energyPoints);
}

unsigned int
	NinjaTrap::ninjaShoebox(FragTrap& target)
{
	if (_energyPoints < 30)
	{
		std::cout << _name << " is not enough energy to do Ninja Shoebox" << std::endl;
		return (_energyPoints);
	}
	_energyPoints = (_energyPoints > 30 ? _energyPoints - 30 : 0);
	std::cout << _name << " chatted with FragTrap" << std::endl;
	target.beRepaired(30);
	return (_energyPoints);
}

unsigned int
	NinjaTrap::ninjaShoebox(ScavTrap& target)
{
	if (_energyPoints < 50)
	{
		std::cout << _name << " is not enough energy to do Ninja Shoebox" << std::endl;
		return (_energyPoints);
	}
	_energyPoints = (_energyPoints > 50 ? _energyPoints - 50 : 0);
	std::cout << _name << " had dinner with ScavTrap" << std::endl;
	target.beRepaired(50);
	return (_energyPoints);
}

unsigned int
	NinjaTrap::ninjaShoebox(NinjaTrap& target)
{
	if (_energyPoints < 30)
	{
		std::cout << _name << " is not enough energy to do Ninja Shoebox" << std::endl;
		return (_energyPoints);
	}
	_energyPoints = (_energyPoints > 30 ? _energyPoints - 30 : 0);
	std::cout << _name << " hit the NinjaTrap" << std::endl;
	target.takeDamage(_attackDamageMelee);
	return (_energyPoints);
}
