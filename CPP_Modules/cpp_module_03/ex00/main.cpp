/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 03:35:14 by seyu              #+#    #+#             */
/*   Updated: 2021/04/04 01:56:50 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

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
	namedFrag.meleeAttack("seyu");
	namedFrag.takeDamage(20);
	namedFrag.beRepaired(20);
	namedFrag.vaulthunter_dot_exe("First");
	namedFrag.vaulthunter_dot_exe("Second");
	namedFrag.vaulthunter_dot_exe("Third");
	namedFrag.vaulthunter_dot_exe("Forth");
	namedFrag.vaulthunter_dot_exe("Fifth");
}
