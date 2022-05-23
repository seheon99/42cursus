/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 05:57:31 by seyu              #+#    #+#             */
/*   Updated: 2021/04/04 06:37:01 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

int	main()
{
	std::srand(time(NULL));

	ClapTrap	clap = ClapTrap("Clapclap");
	FragTrap	frag = FragTrap("Fragfrag");
	ScavTrap	scav = ScavTrap("Scavscav");
	NinjaTrap	ninjaOne = NinjaTrap("Ninja_one");
	NinjaTrap	ninjaTwo = NinjaTrap("Ninja_two");

	ninjaOne.ninjaShoebox(clap);
	ninjaOne.ninjaShoebox(frag);
	ninjaOne.ninjaShoebox(scav);
	ninjaOne.ninjaShoebox(ninjaTwo);
}
