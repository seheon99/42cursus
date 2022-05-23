/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 03:35:37 by seyu              #+#    #+#             */
/*   Updated: 2021/04/04 06:28:35 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap
{
public:
	FragTrap(std::string name = "Fragtrap");
	FragTrap(FragTrap const& obj);
	~FragTrap();

	FragTrap&		operator=(FragTrap const& other);
	unsigned int	vaulthunter_dot_exe(std::string const& target);
};

#endif
