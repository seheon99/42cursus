/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 04:45:39 by seyu              #+#    #+#             */
/*   Updated: 2021/04/04 05:12:48 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ScavTrap.hpp"

#define RANDOM_SELECT(VAL, TYPE) (VAL[std::rand() % (sizeof(VAL) / sizeof(TYPE))])

ScavTrap::ScavTrap(std::string name) : ClapTrap(100, 100, 50, 50, 1, name, 20, 15, 3)
{
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const& obj)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = obj;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap&
	ScavTrap::operator=(ScavTrap const& other)
{
	(ClapTrap)*this = (ClapTrap)other;
	return (*this);
}

std::string
	ScavTrap::challengeNewcomer()
{
	static const std::string	comer_pool[] = {
		"Maya",
		"Salvador",
		"Axton",
		"Zer0",
		"Gaige",
		"Krieg",
	};
	std::string					comer;

	comer = RANDOM_SELECT(comer_pool, std::string);
	std::cout << _name << " challenges " << comer << std::endl;
	return (comer);
}
