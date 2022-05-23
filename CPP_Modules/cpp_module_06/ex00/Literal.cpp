/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Literal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 02:33:38 by seyu              #+#    #+#             */
/*   Updated: 2021/04/12 23:02:15 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>

#include "Literal.hpp"

Literal::Literal()
		: _charValue(0), _intValue(0)
		, _floatValue(0), _doubleValue(0)
		, _charImpossible(false), _intImpossible(false), _floatImpossible(false)
{}

Literal::Literal(const Literal& other)
		: _charValue(other._charValue), _intValue(other._intValue)
		, _floatValue(other._floatValue), _doubleValue(other._doubleValue)
		, _charImpossible(false), _intImpossible(false), _floatImpossible(false)
{}

Literal::~Literal()
{}

Literal::operator char()
{
	return (_charValue);
}

Literal::operator int()
{
	return (_intValue);
}

Literal::operator float()
{
	return (_floatValue);
}

Literal::operator double()
{
	return (_doubleValue);
}

Literal&
	Literal::operator=(const Literal& other)
{
	_charValue = other._charValue;
	_intValue = other._intValue;
	_floatValue = other._floatValue;
	_doubleValue = other._doubleValue;

	_charImpossible = other._charImpossible;
	_intImpossible = other._intImpossible;
	return (*this);
}

void
	Literal::setChar(char value)
{
	_charValue = value;
}

void
	Literal::setInt(int value)
{
	_intValue = value;
}

void
	Literal::setFloat(float value)
{
	_floatValue = value;
}

void
	Literal::setDouble(double value)
{
	_doubleValue = value;
}

bool
	Literal::isCharImpossible()
{
	return (_charImpossible);
}

void
	Literal::setCharImpossible()
{
	_charImpossible = true;
}

void
	Literal::unsetCharImpossible()
{
	_charImpossible = false;
}

bool
	Literal::isIntImpossible()
{
	return (_intImpossible);
}

void
	Literal::setIntImpossible()
{
	_intImpossible = true;
}

void
	Literal::unsetIntImpossible()
{
	_intImpossible = false;
}

bool
	Literal::isFloatImpossible()
{
	return (_floatImpossible);
}

void
	Literal::setFloatImpossible()
{
	_floatImpossible = true;
}

void
	Literal::unsetFloatImpossible()
{
	_floatImpossible = false;
}

std::ostream&
	operator<<(std::ostream& out, Literal& self)
{
	if (self.isCharImpossible())
		out << "char: impossible" << std::endl;
	else if (static_cast<char>(self) >= 0x1f && static_cast<char>(self) < 0x7f)
		out << "char: " << static_cast<char>(self) << std::endl;
	else
		out << "char: Non displayable" << std::endl;

	if (self.isIntImpossible())
		out << "int: impossible" << std::endl;
	else
		out << "int: " << static_cast<int>(self) << std::endl;

	if (self.isFloatImpossible())
		out << "float: impossible" << std::endl;
	else if (static_cast<float>(self) == static_cast<long long>(static_cast<float>(self)))
		out << "float: " << static_cast<float>(self) << ".0f" << std::endl;
	else
		out << "float: " << static_cast<float>(self) << "f" << std::endl;

	if (static_cast<double>(self) == static_cast<long long>(static_cast<double>(self)))
		out << "double: " << static_cast<double>(self) << ".0" << std::endl;
	else
		out << "double: " << static_cast<double>(self) << std::endl;
	return (out);
}
