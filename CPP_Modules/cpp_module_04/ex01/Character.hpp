/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 05:04:51 by seyu              #+#    #+#             */
/*   Updated: 2021/04/08 01:40:57 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include <ostream>

# include "AWeapon.hpp"
# include "Enemy.hpp"

class	Character
{
public:
	Character(std::string const& name);
	Character(Character const& other);
	~Character();

	Character&	operator=(Character const& other);

	void		recoverAP();
	void		equip(AWeapon *weapon);
	void		attack(Enemy *enemy);
	std::string	getName() const;
	std::string	getWeaponName() const;
	int			getAP() const;
	bool		hasWeapon() const;
protected:
	Character();
private:
	std::string	_name;
	int			_ap;
	AWeapon*	_weapon;
};

std::ostream&	operator<<(std::ostream& out, Character const& self);

#endif
