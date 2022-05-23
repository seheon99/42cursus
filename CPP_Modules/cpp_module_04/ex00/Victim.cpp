/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 18:24:30 by seyu              #+#    #+#             */
/*   Updated: 2021/04/08 04:39:24 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Victim.hpp"

Victim::Victim()
		: _name(std::string())
{}

Victim::Victim(std::string name)
		: _name(name)
{
	std::cout << "Some random victim called " << _name << " just appeared!" << std::endl;
}

Victim::Victim(Victim const& obj)
{
	std::cout << "Some random victim called " << _name << " just appeared!" << std::endl;
	*this = obj;
}

Victim::~Victim()
{
	std::cout << "Victim " << _name << " just died for no apparent reason!" << std::endl;
}

Victim&
	Victim::operator=(Victim const& other)
{
	_name = other._name;
	return (*this);
}

std::ostream&
	Victim::introduceSelf(std::ostream& out) const
{
	out << "I'm " << _name << " and I like otters!" << std::endl;
	return (out);
}

void
	Victim::getPolymorphed() const
{
	std::cout << _name << " has been turned into a cute little sheep!" << std::endl;
}

std::ostream&
	operator<<(std::ostream& out, Victim const& self)
{
	return (self.introduceSelf(out));
}
