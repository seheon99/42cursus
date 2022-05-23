/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 04:59:27 by seyu              #+#    #+#             */
/*   Updated: 2021/04/04 06:36:44 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

static void
	testClapTrap(ClapTrap& tester)
{
	tester.meleeAttack("Minion");
	tester.rangedAttack("Minions");
}

int	main()
{
	std::srand(time(NULL));
	{
		std::cout << "---------------Test with CL4P-TP---------------" << std::endl;
		ClapTrap	clap("Clapclap");
		testClapTrap(clap);
	}
	{
		std::cout << "---------------Test with FR4G-TP---------------" << std::endl;
		FragTrap	frag("Fragfrag");
		testClapTrap(frag);
	}
	{
		std::cout << "---------------Test with SC4V-TP---------------" << std::endl;
		ScavTrap	scav("Scavscav");
		testClapTrap(scav);
	}
}
