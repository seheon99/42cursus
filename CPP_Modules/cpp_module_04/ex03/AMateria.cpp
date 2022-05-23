/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:34:37 by seyu              #+#    #+#             */
/*   Updated: 2021/04/07 22:41:00 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "AMateria.hpp"

AMateria::AMateria() : _type("noType"), _xp(0) {}
AMateria::AMateria(std::string const& type) : _type(type), _xp(0) {}
AMateria::AMateria(AMateria const& other) { *this = other; }
AMateria::~AMateria() {}

AMateria&
	AMateria::operator=(AMateria const& other)
{
	_type = other._type;
	_xp = other._xp;
	return (*this);
}

std::string const&	AMateria::getType() const { return (_type); }
unsigned int		AMateria::getXP() const { return (_xp); }

void
	AMateria::use(ICharacter& target)
{
	(void)target;
	_xp += 10;
}
