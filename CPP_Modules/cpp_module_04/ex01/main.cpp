/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 05:28:50 by seyu              #+#    #+#             */
/*   Updated: 2021/04/08 04:12:20 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Character.hpp"
#include "Enemy.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include "AWeapon.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"

int	main()
{
	std::cout << "--------------Subject main--------------" << std::endl;
	{
		Character*	me = new Character("me");

		std::cout << *me;

		Enemy*		b = new RadScorpion();

		AWeapon*	pr = new PlasmaRifle();
		AWeapon*	pf = new PowerFist();

		me->equip(pr);
		std::cout << *me;
		me->equip(pf);

		me->attack(b);
		std::cout << *me;
		me->equip(pr);
		std::cout << *me;
		me->attack(b);
		std::cout << *me;
		me->attack(b);
		std::cout << *me;
	}
	std::cout << "-----------------MyMain-----------------" << std::endl;
	{
		std::cout << "          ----Constructors----          " << std::endl;
		Character	seyu("seyu");
		Enemy*		mutant = new SuperMutant();
		AWeapon*	pr = new PlasmaRifle();
		AWeapon*	pf = new PowerFist();

		std::cout << "          ----Equip weapon----          " << std::endl;
		std::cout << seyu;
		seyu.equip(pr);
		std::cout << seyu;
		seyu.equip(pf);
		std::cout << seyu;
		seyu.equip(NULL);
		std::cout << seyu;

		std::cout << "          -Fight with SMutant-          " << std::endl;
		seyu.equip(pr);
		seyu.attack(mutant);
		seyu.attack(mutant);
		seyu.attack(mutant);
		seyu.attack(mutant);
		std::cout << seyu;

		std::cout << "          -New enemy appeared-          " << std::endl;
		Enemy*		blackHole = new Enemy(7, "Black Hole");
		seyu.attack(blackHole);

		std::cout << "          -----Destructor-----          " << std::endl;
		delete mutant;
		delete pr;
		delete pf;

		std::cout << "          Assignment operators          " << std::endl;
		std::cout << "** Character" << std::endl;
		Character	myFriend("friend");
		std::cout << myFriend;
		myFriend = seyu;
		std::cout << myFriend;
	}

	return (0);
}
