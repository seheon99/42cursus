/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 12:05:00 by seyu              #+#    #+#             */
/*   Updated: 2021/04/06 12:22:56 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine()
{
	std::cout << "Tactical Marine ready for battle!" << std::endl;
}

TacticalMarine::TacticalMarine(TacticalMarine const& other)
{
	std::cout << "Tactical Marine ready for battle!" << std::endl;
	*this = other;
}

TacticalMarine::~TacticalMarine()
{
	std::cout << "Aaargh..." << std::endl;
}

TacticalMarine&
	TacticalMarine::operator=(TacticalMarine const& other)
{
	ISpaceMarine::operator=(other);
	return (*this);
}

ISpaceMarine*
	TacticalMarine::clone() const
{
	return (new TacticalMarine);
}

void
	TacticalMarine::battleCry() const
{
	std::cout << "For the holy PLOT!" << std::endl;
}

void
	TacticalMarine::rangedAttack() const
{
	std::cout << "* attacks with a bolter *" << std::endl;
}

void
	TacticalMarine::meleeAttack() const
{
	std::cout << "* attacks with a chainsword *" << std::endl;
}
