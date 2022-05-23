/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 04:57:40 by seyu              #+#    #+#             */
/*   Updated: 2021/04/06 06:23:57 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "SuperMutant.hpp"

SuperMutant::SuperMutant() : Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
}
SuperMutant::SuperMutant(SuperMutant const& other) { *this = other; }
SuperMutant::~SuperMutant()
{
	std::cout << "Aaargh..." << std::endl;
}

SuperMutant&
	SuperMutant::operator=(SuperMutant const& other)
{
	Enemy::operator=(other);
	return (*this);
}

void
	SuperMutant::takeDamage(int damage)
{
	Enemy::takeDamage(damage - 3);
}
