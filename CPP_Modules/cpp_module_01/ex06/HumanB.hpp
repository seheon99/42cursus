/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 05:21:43 by seyu              #+#    #+#             */
/*   Updated: 2021/03/24 05:33:37 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class	HumanB
{
private:
	std::string	_name;
	Weapon*		_weapon;
public:
	HumanB(std::string name);
	void	setWeapon(Weapon& weapon);
	void	attack();
};

#endif
