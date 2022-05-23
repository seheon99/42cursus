/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 03:22:59 by seyu              #+#    #+#             */
/*   Updated: 2021/04/08 04:42:02 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Peon.hpp"

Peon::Peon()
	: Victim()
{}

Peon::Peon(std::string name) : Victim(name)
{
	std::cout << "Zog zog" << std::endl;
}

Peon::Peon(Peon const& obj)
{
	std::cout << "Zog zog" << std::endl;
	*this = obj;
}

Peon::~Peon()
{
	std::cout << "Bleuark..." << std::endl;
}

Peon&
	Peon::operator=(Peon const& other)
{
	Victim::operator=(other);
	return (*this);
}

void
	Peon::getPolymorphed() const
{
	std::cout << _name << " has been turned into a pink pony!" << std::endl;
}
