/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 18:31:48 by seyu              #+#    #+#             */
/*   Updated: 2021/04/07 20:42:08 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class	MateriaSource : public IMateriaSource
{
public:
	MateriaSource();
	MateriaSource(MateriaSource const& other);
	virtual ~MateriaSource();

	MateriaSource&		operator=(MateriaSource const& other);
	virtual void		learnMateria(AMateria* source);
	virtual AMateria*	createMateria(std::string const& type);
private:
	static int const	_numSourcesMax = 4;
	int					_numSources;
	AMateria*			_sources[4];
};

#endif
