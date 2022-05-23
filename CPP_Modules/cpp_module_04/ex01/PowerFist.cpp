/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 04:40:59 by seyu              #+#    #+#             */
/*   Updated: 2021/04/08 01:40:04 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "PowerFist.hpp"

PowerFist::PowerFist() : AWeapon("Power Fist", 50, 8) {}
PowerFist::PowerFist(PowerFist const& other)
{
	*this = other;
}
PowerFist::~PowerFist() {}

PowerFist&
	PowerFist::operator=(PowerFist const& other)
{
	AWeapon::operator=(other);
	return (*this);
}

void
	PowerFist::attack() const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
