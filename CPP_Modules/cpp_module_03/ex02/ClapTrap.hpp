/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 03:17:41 by seyu              #+#    #+#             */
/*   Updated: 2021/04/04 07:06:58 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class	ClapTrap
{
public:
	ClapTrap(std::string const& name = "Claptrap");
	ClapTrap(
		unsigned int hitPoints, unsigned int hitPointsMax,
		unsigned int energyPoints, unsigned int energyPointsMax,
		unsigned int level, std::string name,
		unsigned int attackDamageMelee, unsigned int attackDamageRanged,
		unsigned int armorDamageReduction
	);
	ClapTrap(ClapTrap const& obj);
	~ClapTrap();

	ClapTrap&		operator=(ClapTrap const& other);
	unsigned int	rangedAttack(std::string const& target) const;
	unsigned int	meleeAttack(std::string const& target) const;
	unsigned int	takeDamage(unsigned int amount);
	unsigned int	beRepaired(unsigned int amount);
protected:
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

#endif
