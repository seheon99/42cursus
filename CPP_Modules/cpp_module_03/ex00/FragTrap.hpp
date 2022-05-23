/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:01:42 by seyu              #+#    #+#             */
/*   Updated: 2021/04/04 03:25:00 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <ostream>
# include <string>

class	FragTrap
{
public:
	FragTrap(std::string name = "FR4G-TP");
	FragTrap(FragTrap const& obj);
	~FragTrap();

	unsigned int	rangedAttack(std::string const& target);
	unsigned int	meleeAttack(std::string const& target);
	unsigned int	takeDamage(unsigned int amount);
	unsigned int	beRepaired(unsigned int amount);
	unsigned int	vaulthunter_dot_exe(std::string const& target);
	FragTrap&		operator=(const FragTrap& other);
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
std::ostream&	operator<<(std::ostream& out, const FragTrap& self);

#endif
