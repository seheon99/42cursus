/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 03:29:26 by seyu              #+#    #+#             */
/*   Updated: 2021/04/04 07:07:02 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string const& name) :
		_hitPoints(100), _hitPointsMax(100),
		_energyPoints(25), _energyPointsMax(25),
		_level(1), _name(name),
		_attackDamageMelee(10), _attackDamageRanged(5),
		_armorDamageReduction(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(
		unsigned int hitPoints, unsigned int hitPointsMax,
		unsigned int energyPoints, unsigned int energyPointsMax,
		unsigned int level, std::string name,
		unsigned int attackDamageMelee, unsigned int attackDamageRanged,
		unsigned int armorDamageReduction
	) :	_hitPoints(hitPoints), _hitPointsMax(hitPointsMax),
		_energyPoints(energyPoints), _energyPointsMax(energyPointsMax),
		_level(level), _name(name),
		_attackDamageMelee(attackDamageMelee), _attackDamageRanged(attackDamageRanged),
		_armorDamageReduction(armorDamageReduction)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const& obj)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = obj;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap&
	ClapTrap::operator=(ClapTrap const& other)
{
	if (this == &other)
		return (*this);
	_hitPoints = other._hitPoints;
	_hitPointsMax = other._hitPointsMax;
	_energyPoints = other._energyPoints;
	_energyPointsMax = other._energyPointsMax;
	_level = other._level;
	_name = other._name;
	_attackDamageMelee = other._attackDamageMelee;
	_attackDamageRanged = other._attackDamageRanged;
	_armorDamageReduction = other._armorDamageReduction;
	return (*this);
}

unsigned int
	ClapTrap::rangedAttack(std::string const& target) const
{
	std::cout << _name << " attacks " << target << " at range, causing "
			<< _attackDamageRanged << " points of damage!" << std::endl;
	return (_attackDamageRanged);
}

unsigned int
	ClapTrap::meleeAttack(std::string const& target) const
{
	std::cout << _name << " attacks " << target << " at melee, causing "
			<< _attackDamageMelee << " points of damage!" << std::endl;
	return (_attackDamageMelee);
}

unsigned int
	ClapTrap::takeDamage(unsigned int amount)
{
	amount = (amount > _armorDamageReduction ? amount - _armorDamageReduction : 0);
	std::cout << _name << " is damaged " << amount << " points of damage!" << std::endl;
	_hitPoints = (_hitPoints > amount ? _hitPoints - amount : 0);
	return (_hitPoints);
}

unsigned int
	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << _name << " is repaired " << amount << " points of damage!" << std::endl;
	_hitPoints = std::min(_hitPoints + amount, _hitPointsMax);
	return (_hitPoints);
}
