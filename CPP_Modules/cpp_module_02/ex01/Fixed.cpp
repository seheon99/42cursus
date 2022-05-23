/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 17:43:49 by seyu              #+#    #+#             */
/*   Updated: 2021/03/31 04:55:34 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>

Fixed::Fixed() : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	_rawBits = value << _numFractBits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	_rawBits = roundf(value * (1 << _numFractBits));
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Assignation operator called" << std::endl;
	_rawBits = other.getRawBits();
	return (*this);
}

float	Fixed::toFloat() const
{
	return ((float)_rawBits / (1 << _numFractBits));
}

int		Fixed::toInt() const
{
	return ((float)_rawBits / (1 << _numFractBits));
}

int		Fixed::getRawBits() const
{
	return (_rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	_rawBits = raw;
}

std::ostream&	operator<<(std::ostream& out, const Fixed& self)
{
	out << self.toFloat();
	return (out);
}
