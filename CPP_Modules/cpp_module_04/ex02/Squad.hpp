/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 07:35:45 by seyu              #+#    #+#             */
/*   Updated: 2021/04/08 03:32:39 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP
# define SQUAD_HPP

# include "ISquad.hpp"

class	Squad : public ISquad
{
public:
	Squad();
	Squad(Squad const& other);
	virtual ~Squad();

	Squad&	operator=(Squad const& other);

	virtual int				getCount() const;
	virtual ISpaceMarine*	getUnit(int index) const;
	virtual int				push(ISpaceMarine* unit);
private:
	void			_moreCapacity();
	void			_clear();

	int				_numUnits;
	int				_capacity;
	ISpaceMarine**	_units;
};

#endif
