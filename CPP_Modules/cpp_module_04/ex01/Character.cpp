/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 05:08:51 by seyu              #+#    #+#             */
/*   Updated: 2021/04/08 04:08:35 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Character.hpp"

Character::Character()
		: _name(std::string()), _ap(0), _weapon(NULL)
{}

Character::Character(std::string const& name)
		: _name(name), _ap(40), _weapon(NULL)
{}

Character::Character(Character const& other)
{
	*this = other;
}

Character::~Character()
{}

Character&
	Character::operator=(Character const& other)
{
	_name = other._name;
	_ap = other._ap;
	_weapon = other._weapon;
	return (*this);
}

std::ostream&
	operator<<(std::ostream& out, Character const& self)
{
	if (self.hasWeapon())
		out << self.getName() << " has "
			<< self.getAP() << " AP and wields a "
			<< self.getWeaponName() << std::endl;
	else
		out << self.getName() << " has "
			<< self.getAP() << " AP and is unarmed" << std::endl;
	return (out);
}

void
	Character::recoverAP() { _ap = std::min(_ap + 10, 40); }

void
	Character::equip(AWeapon *weapon) { _weapon = weapon; }

void
	Character::attack(Enemy *enemy)
{
	if (enemy == NULL || _weapon == NULL || _ap < _weapon->getAPCost())
		return ;
	std::cout << _name << " attacks " << enemy->getType() \
			<< " with a " << _weapon->getName() << std::endl;
	_ap -= _weapon->getAPCost();
	_weapon->attack();
	enemy->takeDamage(_weapon->getDamage());
	if (enemy->getHP() <= 0)
	{
		std::cout << enemy->getType() << " just died in a critical attack!" << std::endl;
		delete enemy;
	}
}

std::string
	Character::getName() const
{
	return (_name);
}

std::string
	Character::getWeaponName() const
{
	if (_weapon == NULL)
		return ("noWeapon");
	return (_weapon->getName());
}

int	Character::getAP() const
{
	return (_ap);
}

bool
	Character::hasWeapon() const
{
	return (_weapon != NULL);
}
