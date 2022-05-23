/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 06:05:20 by seyu              #+#    #+#             */
/*   Updated: 2021/04/04 06:50:56 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

# include "FragTrap.hpp"
# include "NinjaTrap.hpp"

class	SuperTrap : public FragTrap, public NinjaTrap
{
public:
	SuperTrap(std::string const& name = "Supertrap");
	SuperTrap(SuperTrap const& other);
	~SuperTrap();

	SuperTrap&		operator=(SuperTrap const& other);
	unsigned int	rangedAttack(std::string const& target);
	unsigned int	meleeAttack(std::string const& target);
};

#endif
