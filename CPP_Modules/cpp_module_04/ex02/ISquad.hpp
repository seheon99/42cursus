/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISquad.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 06:55:40 by seyu              #+#    #+#             */
/*   Updated: 2021/04/06 07:39:48 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISQUAD_HPP
# define ISQUAD_HPP

# include "ISpaceMarine.hpp"

class	ISquad
{
public:
	virtual	~ISquad() {}

	virtual int				getCount() const = 0;
	virtual ISpaceMarine*	getUnit(int index) const = 0;
	virtual int				push(ISpaceMarine* unit) = 0;
};

#endif
