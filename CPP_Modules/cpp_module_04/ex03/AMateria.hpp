/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:27:04 by seyu              #+#    #+#             */
/*   Updated: 2021/04/07 21:11:13 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>

class	AMateria;
# include "ICharacter.hpp"

class	AMateria
{
public:
	AMateria();
	AMateria(std::string const& type);
	AMateria(AMateria const& other);
	virtual ~AMateria();

	AMateria&	operator=(AMateria const& other);

	std::string	const&	getType() const;
	unsigned int		getXP() const;

	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);
private:
	std::string			_type;
	unsigned int		_xp;
};

#endif
