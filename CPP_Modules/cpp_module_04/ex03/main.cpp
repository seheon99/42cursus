/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 20:55:53 by seyu              #+#    #+#             */
/*   Updated: 2021/04/08 04:37:19 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"

int	main()
{
	std::cout << "--------------Subject main--------------" << std::endl;
	{
		IMateriaSource*	src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter*		me = new Character("me");

		AMateria*		tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter*		bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}
	std::cout << "-----------------MyMain-----------------" << std::endl;
	{
		IMateriaSource*	src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter*		me = new Character("seyu");

		AMateria*		tmp;
		tmp = src->createMateria("fire");
		me->equip(tmp);
		tmp = src->createMateria(std::string());
		me->equip(tmp);
		me->unequip(0);
		me->unequip(-1);
		me->unequip(100);

		ICharacter*		bob = new Character("bob");
		me->use(-1, *bob);
		me->use(0, *bob);
		me->use(1, *bob);
		me->use(1000, *bob);

		delete bob;
		delete me;
		delete src;
	}

	return (0);
}
