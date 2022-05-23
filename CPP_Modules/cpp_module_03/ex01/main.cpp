/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 03:35:14 by seyu              #+#    #+#             */
/*   Updated: 2021/04/04 03:15:50 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

#include <iostream>
#include <string>
#include <cstdlib>

int	main()
{
	std::srand(time(NULL));

	FragTrap	defaultFrag;
	FragTrap	namedFrag("ClapTrap");

	defaultFrag.rangedAttack("Minions");
	defaultFrag.takeDamage(4);
	defaultFrag.takeDamage(400);
	defaultFrag.beRepaired(2);
	namedFrag.meleeAttack("Minion");
	namedFrag.takeDamage(20);
	namedFrag.beRepaired(20);
	namedFrag.vaulthunter_dot_exe("First minion");
	namedFrag.vaulthunter_dot_exe("Second minion");
	namedFrag.vaulthunter_dot_exe("Third minion");
	namedFrag.vaulthunter_dot_exe("Forth minion");
	namedFrag.vaulthunter_dot_exe("Fifth minion");

	std::cout << "----------------------------------------" << std::endl;

	ScavTrap	defaultScav;
	ScavTrap	namedScav("5c4v");

	defaultScav.rangedAttack("Minions");
	defaultScav.takeDamage(2);
	defaultScav.takeDamage(200);
	defaultScav.beRepaired(4);
	namedScav.meleeAttack("Minion");
	namedScav.takeDamage(20);
	namedScav.beRepaired(20);
	namedScav.challengeNewcomer();
	namedScav.challengeNewcomer();
	namedScav.challengeNewcomer();
}
