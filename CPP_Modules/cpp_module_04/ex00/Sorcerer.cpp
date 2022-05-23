/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:00:08 by seyu              #+#    #+#             */
/*   Updated: 2021/04/08 04:42:50 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Sorcerer.hpp"

Sorcerer::Sorcerer()
	: _name(std::string()), _title(std::string())
{}

Sorcerer::Sorcerer(std::string name, std::string title) : _name(name), _title(title)
{
	std::cout << _name << ", " << _title << ", is born!" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const& obj)
{
	*this = obj;
	std::cout << _name << ", " << _title << ", is born!" << std::endl;
}

Sorcerer::~Sorcerer()
{
	std::cout << _name << ", " << _title << \
			", is dead. Consequences will never be the same!" << std::endl;
}

Sorcerer&
	Sorcerer::operator=(Sorcerer const& other)
{
	_name = other._name;
	_title = other._title;
	return (*this);
}

std::ostream&
	Sorcerer::introduceSelf(std::ostream& out) const
{
	out << "I am " << _name << ", " << _title << ", and I like ponies!" << std::endl;
	return (out);
}

void
	Sorcerer::polymorph(Victim const& target) const
{
	target.getPolymorphed();
}

std::ostream&
	operator<<(std::ostream& out, Sorcerer const& self)
{
	return (self.introduceSelf(out));
}
