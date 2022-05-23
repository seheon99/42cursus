/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 03:59:03 by seyu              #+#    #+#             */
/*   Updated: 2021/04/08 01:34:46 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon()
		: _name(std::string()), _damage(0), _apCost(0)
{}

AWeapon::AWeapon(std::string name, int damage, int cost)
		: _name(name), _damage(damage), _apCost(cost)
{}

AWeapon::AWeapon(AWeapon const& other)
{
	*this = other;
}

AWeapon::~AWeapon()
{}

AWeapon&
	AWeapon::operator=(AWeapon const& other)
{
	_name = other._name;
	_damage = other._damage;
	_apCost = other._apCost;
	return (*this);
}

std::string const
	AWeapon::getName() const
{
	return (_name);
}

int	AWeapon::getDamage() const
{
	return (_damage);
}

int	AWeapon::getAPCost() const
{
	return (_apCost);
}
