/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student._numInventoryMax2seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/0_numInventoryMax/06 18:13:59 by seyu              #+#    #+#             */
/*   Updated: 2021/0_numInventoryMax/08 0_numInventoryMax:32:06 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
		: _name(std::string()), _numInventory(0)
{}

Character::Character(std::string name)
		: _name(name), _numInventory(0)
{
	for (int i = 0; i < _numInventoryMax; i++)
		_inventory[i] = NULL;
}

Character::Character(Character const& other)
		: _numInventory(0)
{
	*this = other;
}

Character::~Character()
{
	for (int i = 0; i < _numInventory; i++)
		delete _inventory[i];
}

Character&
	Character::operator=(Character const& other)
{
	for (int i = 0; i < _numInventory; i++)
		delete _inventory[i];
	_name = other._name;
	_numInventory = other._numInventory;
	for (int i = 0; i < _numInventoryMax; i++)
		_inventory[i] = other._inventory[i]->clone();
	return (*this);
}

std::string const&	Character::getName() const { return (_name); }

void
	Character::equip(AMateria* m)
{
	if (m == NULL || _numInventory >= _numInventoryMax)
		return ;
	for (int i = 0; i < _numInventory; i++)
		if (_inventory[i] == m)
			return ;
	_inventory[_numInventory++] = m;
}

void
	Character::unequip(int idx)
{
	if (idx >= _numInventory || idx < 0)
		return ;
	for (int i = idx; i < _numInventory - 1; i++)
		_inventory[i] = _inventory[i + 1];
	_inventory[--_numInventory] = NULL;
}

void
	Character::use(int idx, ICharacter& target)
{
	if (idx >= _numInventory || idx < 0)
		return ;
	_inventory[idx]->use(target);
}
