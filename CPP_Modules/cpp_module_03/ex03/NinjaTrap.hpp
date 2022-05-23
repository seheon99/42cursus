/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 05:19:23 by seyu              #+#    #+#             */
/*   Updated: 2021/04/04 06:28:33 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include <string>

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class	NinjaTrap : virtual public ClapTrap
{
public:
	NinjaTrap(std::string name = "NinjaTrap");
	NinjaTrap(NinjaTrap const& obj);
	~NinjaTrap();

	NinjaTrap&		operator=(NinjaTrap const& other);
	unsigned int	ninjaShoebox(ClapTrap& target);
	unsigned int	ninjaShoebox(FragTrap& target);
	unsigned int	ninjaShoebox(ScavTrap& target);
	unsigned int	ninjaShoebox(NinjaTrap& target);
};

#endif
