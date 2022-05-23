/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 04:43:22 by seyu              #+#    #+#             */
/*   Updated: 2021/04/04 06:28:41 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap(std::string name = "Scavtrap");
	ScavTrap(ScavTrap const& obj);
	~ScavTrap();

	ScavTrap&	operator=(ScavTrap const& other);
	std::string	challengeNewcomer();
};

#endif
