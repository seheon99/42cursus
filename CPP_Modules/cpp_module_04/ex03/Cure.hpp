/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:58:51 by seyu              #+#    #+#             */
/*   Updated: 2021/04/06 17:59:34 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class	Cure : public AMateria
{
public:
	Cure();
	Cure(Cure const& other);
	virtual ~Cure();

	Cure&	operator=(Cure const& other);

	virtual AMateria*	clone() const;
	virtual void		use(ICharacter& target);
private:
};

#endif
