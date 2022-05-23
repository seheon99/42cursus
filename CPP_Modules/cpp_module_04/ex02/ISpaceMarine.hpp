/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISpaceMarine.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 06:57:39 by seyu              #+#    #+#             */
/*   Updated: 2021/04/08 01:48:22 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISPACEMARINE_HPP
# define ISPACEMARINE_HPP

class	ISpaceMarine
{
public:
	virtual	~ISpaceMarine() {}

	virtual	ISpaceMarine*	clone() const = 0;
	virtual void			battleCry() const = 0;
	virtual	void			rangedAttack() const = 0;
	virtual	void			meleeAttack() const = 0;
};

#endif
