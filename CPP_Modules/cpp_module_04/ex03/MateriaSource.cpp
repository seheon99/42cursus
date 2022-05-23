/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 18:43:12 by seyu              #+#    #+#             */
/*   Updated: 2021/04/08 04:35:37 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	_numSources = 0;
	for (int i = 0; i < _numSourcesMax; i++)
		_sources[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const& other) { *this = other; }

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < _numSources; i++)
		delete _sources[i];
}

MateriaSource&
	MateriaSource::operator=(MateriaSource const& other)
{
	for (int i = 0; i < _numSources; i++)
	{
		delete _sources[i];
		_sources[i] = NULL;
	}
	_numSources = other._numSources;
	for (int i = 0; i < _numSources; i++)
		_sources[i] = other._sources[i];
	return (*this);
}

void
	MateriaSource::learnMateria(AMateria* source)
{
	if (_numSources >= _numSourcesMax || source == NULL)
		return ;
	for (int i = 0; i < _numSources; i++)
		if (source->getType() == _sources[i]->getType())
			return ;
	_sources[_numSources++] = source;
}

AMateria*
	MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < _numSources; i++)
		if (_sources[i]->getType() == type)
			return (_sources[i]->clone());
	return (NULL);
}
