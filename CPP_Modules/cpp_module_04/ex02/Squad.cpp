/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 07:47:45 by seyu              #+#    #+#             */
/*   Updated: 2021/04/08 04:52:40 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"

Squad::Squad()
		: _numUnits(0), _capacity(0), _units(0)
{}

Squad::Squad(Squad const& other) : _numUnits(0), _capacity(0), _units(0)
{
	*this = other;
}

Squad::~Squad()
{
	_clear();
}

Squad&
	Squad::operator=(Squad const& other)
{
	if (_capacity > 0)
		_clear();
	if (other._capacity > 0)
	{
		_numUnits = other._numUnits;
		_capacity = other._capacity;
		_units = new ISpaceMarine*[_capacity];
		for (int i = 0; i < other._numUnits; i++)
			_units[i] = other.getUnit(i)->clone();
	}
	return (*this);
}

int	Squad::getCount() const
{
	return (_numUnits);
}

ISpaceMarine*
	Squad::getUnit(int index) const
{
	if (index >= _numUnits || index < 0)
		return (0);
	return (_units[index]);
}

int	Squad::push(ISpaceMarine* unit)
{
	if (unit == 0)
		return (_numUnits);
	for (int i = 0; i < _numUnits; i++)
		if (_units[i] == unit)
			return (_numUnits);
	if (_capacity == 0 || _numUnits == _capacity)
		_moreCapacity();
	_units[_numUnits++] = unit;
	return (_numUnits);
}

void
	Squad::_moreCapacity()
{
	if (_capacity == 0)
	{
		_capacity = 1;
		_units = new ISpaceMarine*[_capacity];
	}
	else if (_numUnits == _capacity)
	{
		ISpaceMarine**	newUnits;

		_capacity *= 2;
		newUnits = new ISpaceMarine*[_capacity];
		for (int i = 0; i < _numUnits; i++)
			newUnits[i] = _units[i];
		delete _units;
		_units = newUnits;
	}
}

void
	Squad::_clear()
{
	if (_units == 0)
		return ;
	for (int i = 0; i < _numUnits; i++)
		delete _units[i];
	delete _units;
	_numUnits = 0;
	_capacity = 0;
	_units = 0;
}
