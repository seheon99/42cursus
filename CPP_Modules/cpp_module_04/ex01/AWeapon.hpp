/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 03:49:56 by seyu              #+#    #+#             */
/*   Updated: 2021/04/08 01:40:43 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
# define AWEAPON_HPP

# include <string>

class	AWeapon
{
public:
	AWeapon(std::string name, int damage, int cost);
	AWeapon(AWeapon const& other);
	virtual ~AWeapon();

	AWeapon&	operator=(AWeapon const& other);

	std::string	const	getName() const;
	int					getAPCost() const;
	int					getDamage() const;
	virtual void		attack() const = 0;
protected:
	AWeapon();
private:
	std::string	_name;
	int			_damage;
	int			_apCost;
};

#endif
