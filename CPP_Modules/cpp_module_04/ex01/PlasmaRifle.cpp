/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 04:32:54 by seyu              #+#    #+#             */
/*   Updated: 2021/04/08 01:18:30 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 21, 5) {}
PlasmaRifle::PlasmaRifle(PlasmaRifle const& other) { *this = other; }
PlasmaRifle::~PlasmaRifle() {}

PlasmaRifle&
	PlasmaRifle::operator=(PlasmaRifle const& other)
{
	AWeapon::operator=(other);
	return (*this);
}

void
	PlasmaRifle::attack() const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
