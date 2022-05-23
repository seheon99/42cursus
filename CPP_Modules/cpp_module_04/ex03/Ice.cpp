/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:53:55 by seyu              #+#    #+#             */
/*   Updated: 2021/04/07 22:41:31 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}
Ice::Ice(Ice const& other) { *this = other; }
Ice::~Ice() {}

Ice&		Ice::operator=(Ice const& other)
{
	AMateria::operator=(other);
	return (*this);
}

AMateria*	Ice::clone() const { return (new Ice(*this)); }

void
	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	AMateria::use(target);
}
