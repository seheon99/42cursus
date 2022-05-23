/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 22:14:54 by seyu              #+#    #+#             */
/*   Updated: 2021/04/04 03:25:27 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "FragTrap.hpp"

#define RANDOM_SELECT(VAL, TYPE) (VAL[std::rand() % (sizeof(VAL) / sizeof(TYPE))])

FragTrap::FragTrap(std::string name) :
		_hitPoints(100), _hitPointsMax(100),
		_energyPoints(100), _energyPointsMax(100),
		_level(1), _name(name),
		_attackDamageMelee(30), _attackDamageRanged(20),
		_armorDamageReduction(5)
{
	static std::string	quote[] = {
		"Hey everybody! Check out my package!",
		"Let's get this party started!",
		"Glitching weirdness is a term of endearment, right?",
		"Recompiling my combat code!",
		"This time it'll be awesome, I promise!",
		"Look out everybody! Things are about to get awesome!",
	};

	std::cout << *this << ": " << RANDOM_SELECT(quote, std::string) << std::endl;
}

FragTrap::FragTrap(FragTrap const& obj)
{
	*this = obj;
}

FragTrap::~FragTrap()
{
	static std::string	quote[] = {
		"Pop pop!",
		"Crit-i-cal!",
		"That looks like it hurts!",
		"WOW! I hit 'em!",
		"Extra ouch!",
		"Shwing!",
	};

	std::cout << *this << ": " << RANDOM_SELECT(quote, std::string) << std::endl;
}

unsigned int
	FragTrap::rangedAttack(std::string const& target)
{
	static std::string	quote[] = {
		"Step right up, to the Bulletnator 9000!",
		"I am a tornado of death and bullets!",
		"Stop me before I kill again, except don't!",
		"Hehehehe, mwaa ha ha ha, MWAA HA HA HA!",
		"I'm on a roll!",
		"Unts unts unts unts!",
		"Ha ha ha! Fall before your robot overlord!",
		"Can't touch this!",
		"Ha! Keep 'em coming!",
		"There is no way this ends badly!",
		"This is why I was built!",
	};

	std::cout << *this << ": " << RANDOM_SELECT(quote, std::string) << std::endl;
	std::cout << _name << " attacks " << target << " at range, causing " << _attackDamageRanged << " points of damage!" << std::endl;
	return (_attackDamageRanged);
}

unsigned int
	FragTrap::meleeAttack(std::string const& target)
{
	static std::string	quote[] = {
		"Hyah!",
		"Heyyah!",
		"Take that!",
		"Bop!",
	};

	std::cout << *this << ": " << RANDOM_SELECT(quote, std::string) << std::endl;
	std::cout << _name << " attacks " << target << " at melee, causing " << _attackDamageMelee << " points of damage!" << std::endl;
	return (_attackDamageMelee);
}

unsigned int
	FragTrap::takeDamage(unsigned int amount)
{
	static std::string	quote[] = {
		"My assets... frozen!",
		"I can't feel my fingers! Gah! I don't have any fingers!",
		"Too cold... can't move!",
		"I am a robot popsicle!",
		"Brrh... So cold... brrh...",
		"Metal gears... frozen solid!",
		"Why do I even feel pain?!",
		"Why did they build me out of galvanized flesh?!",
		"Ow hohoho, that hurts! Yipes!",
		"My robotic flesh! AAHH!",
		"Yikes! Ohhoho!",
		"Woah! Oh! Jeez!",
		"If only my chassis... weren't made of recycled human body parts! Wahahaha!",
	};

	amount = (amount > _armorDamageReduction ? amount - _armorDamageReduction : 0);
	std::cout << *this << ": " << RANDOM_SELECT(quote, std::string) << std::endl;
	std::cout << _name << " is damaged " << amount << " points of damage!" << std::endl;
	_hitPoints = (_hitPoints > amount ? _hitPoints - amount : 0);
	return (_hitPoints);
}

unsigned int
	FragTrap::beRepaired(unsigned int amount)
{
	static std::string	quote[] = {
		"Health! Eww, what flavor is red?",
		"Health over here!",
		"Sweet life juice!",
		"I found health!",
		"Healsies!",
	};

	std::cout << *this << ": " << RANDOM_SELECT(quote, std::string) << std::endl;
	std::cout << _name << " is repaired " << amount << " points of damage!" << std::endl;
	_hitPoints = std::min(_hitPoints + amount, _hitPointsMax);
	return (_hitPoints);
}

unsigned int
	FragTrap::vaulthunter_dot_exe(std::string const& target)
{
	static std::string	quote[] = {
		"This time it'll be awesome, I promise!",
		"Hey everybody, check out my package!",
		"Place your bets!",
		"Defragmenting!",
		"Recompiling my combat code!",
		"Running the sequencer!",
		"It's happening... it's happening!",
		"It's about to get magical!",
		"I'm pulling tricks outta my hat!",
		"You can't just program this level of excitement!",
		"What will he do next?",
		"Things are about to get awesome!",
		"Let's get this party started!",
		"Glitchy weirdness is term of endearment, right?",
		"Push this button, flip this dongle, voila! Help me!",
		"Square the I, carry the 1... YES!",
		"Resequencing combat protocols!",
		"Look out everybody, things are about to get awesome!",
		"I have an IDEA!",
		"Round and around and around she goes!",
		"It's like a box of chocolates...",
		"Step right up to the sequence of Trapping!",
		"Hey everybody, check out my package!",
		"Loading combat packages!",
		"F to the R to the 4 to the G to the WHAAT!",
	};
	static std::string	skill[] = {
		"Clap-In-The-Box",
		"Gun Wizard",
		"Torgue Flesta",
		"Pirate Ship Mode",
		"One Shot Wonder",
		"Laser Inferno",
		"Miniontrap",
		"Meat Unicycle",
		"Funzerker",
		"Mechromagician",
		"Shhhh... Trap!",
		"Blight Bot",
		"Rubber Ducky",
		"Senseless Sacrifice",
		"Medbot",
	};

	if (_energyPoints < 25)
	{
		std::cout << _name << " is not enough energy to execute VaultHunter.EXE." << std::endl;
		return (_energyPoints);
	}
	std::cout << *this << ": " << RANDOM_SELECT(quote, std::string) << std::endl;
	std::cout << _name << " used " << RANDOM_SELECT(skill, std::string) << " skill to " << target << "!" << std::endl;
	return (_energyPoints -= 25);
}

FragTrap&
	FragTrap::operator=(const FragTrap& other)
{
	if (this == &other)
		return (*this);
	_hitPoints = other._hitPoints;
	_hitPointsMax = other._hitPointsMax;
	_energyPoints = other._energyPoints;
	_energyPointsMax = other._energyPointsMax;
	_level = other._level;
	_name = other._name;
	_attackDamageMelee = other._attackDamageMelee;
	_attackDamageRanged = other._attackDamageRanged;
	_armorDamageReduction = other._armorDamageReduction;
	return (*this);

}

std::ostream&
	FragTrap::printSelf(std::ostream& out) const
{
	out << _name << " (" << _level << " lv, FR4G-TP, " << _hitPoints << "/" << _hitPointsMax << ")";
	return (out);
}

std::ostream&
	operator<<(std::ostream& out, const FragTrap& self)
{
	return (self.printSelf(out));
}
