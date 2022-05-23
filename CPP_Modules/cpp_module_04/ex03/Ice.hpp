/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:52:04 by seyu              #+#    #+#             */
/*   Updated: 2021/04/07 21:07:27 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class	Ice : public AMateria
{
public:
	Ice();
	Ice(Ice const& other);
	virtual ~Ice();

	Ice&	operator=(Ice const& other);

	virtual AMateria*	clone() const;
	virtual void		use(ICharacter& target);
private:
};

#endif
