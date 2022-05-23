/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 22:14:54 by seyu              #+#    #+#             */
/*   Updated: 2021/04/04 03:26:19 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ScavTrap.hpp"

#define RANDOM_SELECT(VAL, TYPE) (VAL[std::rand() % (sizeof(VAL) / sizeof(TYPE))])

ScavTrap::ScavTrap(std::string name) :
		_hitPoints(100), _hitPointsMax(100),
		_energyPoints(50), _energyPointsMax(50),
		_level(1), _name(name),
		_attackDamageMelee(20), _attackDamageRanged(15),
		_armorDamageReduction(3)
{
	static std::string	quote_pool[] = {
		"Recompiling my combat code!",
		"This time it'll be awesome, I promise!",
		"Look out everybody! Things are about to get awesome!",
	};

	std::cout << *this << ": " << RANDOM_SELECT(quote_pool, std::string) << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const& obj)
{
	*this = obj;
}

ScavTrap::~ScavTrap()
{
	static std::string	quote_pool[] = {
		"WOW! I hit 'em!",
		"Extra ouch!",
		"Shwing!",
	};

	std::cout << *this << ": " << RANDOM_SELECT(quote_pool, std::string) << std::endl;
}

unsigned int
	ScavTrap::rangedAttack(std::string const& target)
{
	static std::string	quote_pool[] = {
		"Unts unts unts unts!",
		"Ha ha ha! Fall before your robot overlord!",
		"Can't touch this!",
		"Ha! Keep 'em coming!",
		"There is no way this ends badly!",
	};

	std::cout << *this << ": " << RANDOM_SELECT(quote_pool, std::string) << std::endl;
	std::cout << _name << " attacks " << target << " at range, causing " << _attackDamageRanged << " points of damage!" << std::endl;
	return (_attackDamageRanged);
}

unsigned int
	ScavTrap::meleeAttack(std::string const& target)
{
	static std::string	quote_pool[] = {
		"Take that!",
		"Bop!",
	};

	std::cout << *this << ": " << RANDOM_SELECT(quote_pool, std::string) << std::endl;
	std::cout << _name << " attacks " << target << " at melee, causing " << _attackDamageMelee << " points of damage!" << std::endl;
	return (_attackDamageMelee);
}

unsigned int
	ScavTrap::takeDamage(unsigned int amount)
{
	static std::string	quote_pool[] = {
		"Why do I even feel pain?!",
		"Why did they build me out of galvanized flesh?!",
		"Ow hohoho, that hurts! Yipes!",
		"My robotic flesh! AAHH!",
		"Yikes! Ohhoho!",
		"Woah! Oh! Jeez!",
	};

	amount = (amount > _armorDamageReduction ? amount - _armorDamageReduction : 0);
	std::cout << *this << ": " << RANDOM_SELECT(quote_pool, std::string) << std::endl;
	std::cout << _name << " is damaged " << amount << " points of damage!" << std::endl;
	_hitPoints = (_hitPoints > amount ? _hitPoints - amount : 0);
	return (_hitPoints);
}

unsigned int
	ScavTrap::beRepaired(unsigned int amount)
{
	static std::string	quote_pool[] = {
		"Sweet life juice!",
		"I found health!",
	};

	std::cout << *this << ": " << RANDOM_SELECT(quote_pool, std::string) << std::endl;
	std::cout << _name << " is repaired " << amount << " points of damage!" << std::endl;
	_hitPoints = std::min(_hitPoints + amount, _hitPointsMax);
	return (_hitPoints);
}

std::string
	ScavTrap::challengeNewcomer()
{
	static std::string	quote_pool[] = {
		"You versus me! Me versus you! Either way!",
		"I will prove to you my robotic superiority!",
		"Dance battle! Or, you know... regular battle.",
		"Man versus machine! Very tiny streamlined machine!",
		"Care to have a friendly duel?",
	};
	static std::string	comer_pool[] = {
		"Maya",
		"Salvador",
		"Axton",
		"Zer0",
		"Gaige",
		"Krieg",
	};
	std::string			comer;

	if (_energyPoints < 25)
	{
		std::cout << _name << " is not enough energy to challenge new comer!" << std::endl;
		return ("");
	}
	_energyPoints -= 25;
	comer = RANDOM_SELECT(comer_pool, std::string);
	std::cout << *this << ": " << RANDOM_SELECT(quote_pool, std::string) << std::endl;
	std::cout << _name << " challenge to " << comer << "!" << std::endl;
	return (comer);
}

ScavTrap&
	ScavTrap::operator=(const ScavTrap& other)
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

std::ostream&
	ScavTrap::printSelf(std::ostream& out) const
{
	out << _name << " (" << _level << " lv, SC4V-TP, " << _hitPoints << "/" << _hitPointsMax << ")";
	return (out);
}

std::ostream&
	operator<<(std::ostream& out, const ScavTrap& self)
{
	return (self.printSelf(out));
}
