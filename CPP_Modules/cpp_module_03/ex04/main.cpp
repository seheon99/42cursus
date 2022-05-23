/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 05:57:31 by seyu              #+#    #+#             */
/*   Updated: 2021/04/04 07:16:28 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

int	main()
{
	std::srand(time(NULL));

	ClapTrap	clap = ClapTrap("Clapclap");
	FragTrap	frag = FragTrap("Fragfrag");
	ScavTrap	scav = ScavTrap("Scavscav");
	NinjaTrap	ninja = NinjaTrap("Ninjaman");
	SuperTrap	super = SuperTrap("Superman");

	super.ninjaShoebox(clap);
	super.ninjaShoebox(ninja);
	super.vaulthunter_dot_exe("Minions");
	super.vaulthunter_dot_exe("Minions");
}
