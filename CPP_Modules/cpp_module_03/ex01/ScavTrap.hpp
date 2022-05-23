/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 01:39:38 by seyu              #+#    #+#             */
/*   Updated: 2021/04/04 03:25:54 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>

class	ScavTrap
{
public:
	ScavTrap(std::string name = "SC4V-TP");
	ScavTrap(ScavTrap const& obj);
	~ScavTrap();

	unsigned int	rangedAttack(std::string const& target);
	unsigned int	meleeAttack(std::string const& target);
	unsigned int	takeDamage(unsigned int amount);
	unsigned int	beRepaired(unsigned int amount);
	std::string		challengeNewcomer();
	ScavTrap&		operator=(const ScavTrap& other);
	std::ostream&	printSelf(std::ostream& out) const;
private:
	unsigned int	_hitPoints;
	unsigned int	_hitPointsMax;
	unsigned int	_energyPoints;
	unsigned int	_energyPointsMax;
	unsigned int	_level;
	std::string		_name;
	unsigned int	_attackDamageMelee;
	unsigned int	_attackDamageRanged;
	unsigned int	_armorDamageReduction;
};

std::ostream&	operator<<(std::ostream& out, const ScavTrap& self);

#endif
