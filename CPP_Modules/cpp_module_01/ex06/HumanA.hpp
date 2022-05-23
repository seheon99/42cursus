/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 05:16:22 by seyu              #+#    #+#             */
/*   Updated: 2021/03/24 05:33:34 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class	HumanA
{
private:
	std::string	_name;
	Weapon&		_weapon;
public:
	HumanA(std::string name, Weapon &weapon);
	void	attack();
};

#endif
