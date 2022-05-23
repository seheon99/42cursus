/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 18:00:15 by seyu              #+#    #+#             */
/*   Updated: 2021/04/07 22:41:49 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}
Cure::Cure(Cure const& other) { *this = other; }
Cure::~Cure() {}

Cure&		Cure::operator=(Cure const& other)
{
	AMateria::operator=(other);
	return (*this);
}

AMateria*	Cure::clone() const { return (new Cure(*this)); }

void
	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	AMateria::use(target);
}
