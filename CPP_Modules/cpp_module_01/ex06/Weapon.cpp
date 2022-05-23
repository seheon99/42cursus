/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 05:14:29 by seyu              #+#    #+#             */
/*   Updated: 2021/03/24 05:29:56 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() : type("noType")
{}

Weapon::Weapon(std::string type) : type(type)
{}

const std::string&
	Weapon::getType()
{
	return (type);
}

void
	Weapon::setType(std::string weapon_type)
{
	type = weapon_type;
}
