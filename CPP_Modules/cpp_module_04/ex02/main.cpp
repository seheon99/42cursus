/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 12:18:07 by seyu              #+#    #+#             */
/*   Updated: 2021/04/08 04:23:00 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "ISpaceMarine.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"
#include "ISquad.hpp"
#include "Squad.hpp"

int	main()
{
	std::cout << "--------------Subject main--------------" << std::endl;
	{
		ISpaceMarine*	bob = new TacticalMarine;
		ISpaceMarine*	jim = new AssaultTerminator;

		ISquad*			vlc = new Squad;
		vlc->push(bob);
		vlc->push(jim);
		for (int i = 0; i < vlc->getCount(); i++)
		{
			ISpaceMarine*	cur = vlc->getUnit(i);

			cur->battleCry();
			cur->rangedAttack();
			cur->meleeAttack();
		}
		delete vlc;
	}
	std::cout << "-----------------MyMain-----------------" << std::endl;
	{
		Squad	mySquad;

		std::srand(std::time(NULL));

		std::cout << "          ----Constructors----          " << std::endl;
		for (int i = 0; i < 100; i++)
		{
			if (std::rand() % 2 == 0)
				mySquad.push(new AssaultTerminator);
			else
				mySquad.push(new TacticalMarine);
		}
		std::cout << "          -------Action-------          " << std::endl;
		for (int i = 0; i < 100; i++)
		{
			mySquad.getUnit(i)->battleCry();
			if (std::rand() % 2 == 0)
				mySquad.getUnit(i)->rangedAttack();
			else
				mySquad.getUnit(i)->meleeAttack();
		}
		std::cout << "          -------Counts-------          " << std::endl;
		std::cout << "getCount() = " << mySquad.getCount() << std::endl;
		std::cout << "push(getUnit(0) = " << mySquad.push(mySquad.getUnit(0)) << std::endl;
		std::cout << "push(getUnit(-1) = " << mySquad.push(mySquad.getUnit(-1)) << std::endl;
		std::cout << "getUnit(-1) = " << mySquad.getUnit(-1) << std::endl;
		std::cout << "getUnit(420000000) = " << mySquad.getUnit(420000000) << std::endl;
		std::cout << "          --Copy constructor--          " << std::endl;
		Squad	copySquad(mySquad);
		std::cout << "          -----Destructor-----          " << std::endl;
	}
	return (0);
}
