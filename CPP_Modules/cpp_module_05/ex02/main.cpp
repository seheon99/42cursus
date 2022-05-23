/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 22:48:38 by seyu              #+#    #+#             */
/*   Updated: 2021/04/11 04:08:09 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::srand(std::time(NULL));
	std::cout << "---Check all funtions are valid" << std::endl;
	{
		Bureaucrat	me("seyu", 5);
		Bureaucrat	br("agent", 15);

		std::cout << "Our bureaucrats:" << std::endl;
		std::cout << me << std::endl << br << std::endl;

		ShrubberyCreationForm	scf("Innovation Academy");
		RobotomyRequestForm		rrf("Coffee maker");
		PresidentialPardonForm	ppf("Jellies");

		std::cout << std::endl;
		std::cout << "Our forms:" << std::endl;
		std::cout << scf << std::endl << rrf << std::endl << ppf << std::endl;

		std::cout << std::endl;
		std::cout << "seyu try to execute forms without sign: " << std::endl;
		me.executeForm(scf);
		me.executeForm(rrf);
		me.executeForm(ppf);

		std::cout << std::endl;
		std::cout << "Agent try to sign forms: " << std::endl;
		br.signForm(scf);
		br.signForm(rrf);
		br.signForm(ppf);

		std::cout << std::endl;
		std::cout << "seyu try to execute forms with sign: " << std::endl;
		me.executeForm(scf);
		me.executeForm(rrf);
		me.executeForm(ppf);

		std::cout << std::endl;
		std::cout << "The output of execution " << scf << std::endl;
		system("cat Innovation\\ Academy_shrubbery");
	}
	std::cout << std::endl;
	std::cout << "---Check all cases is executable with no crash" << std::endl;
	{
		Bureaucrat	*workers[16];

		std::cout << "Our bureaucrats:" << std::endl;
		for (int i = 15; i > 0; i--)
		{
			workers[i] = new Bureaucrat("Grade" + std::to_string(i * 10), i * 10);
			std::cout << *workers[i] << std::endl;
		}
		workers[0] = new Bureaucrat("Grade1", 1);
		std::cout << *workers[0] << std::endl;

		std::cout << std::endl;
		std::cout << "Shrubbery Creation Forms cases: ";
		ShrubberyCreationForm	scf("42seoul");
		std::cout << scf << std::endl;
		for (int i = 15; i >= 0; i--)
		{
			ShrubberyCreationForm	scf("42seoul" + std::to_string(workers[i]->getGrade()));

			workers[i]->signForm(scf);
			workers[i]->executeForm(scf);
		}

		std::cout << std::endl;
		std::cout << "Robotomy Request Forms cases: ";
		RobotomyRequestForm		rrf("Reporter");
		std::cout << rrf << std::endl;
		for (int i = 15; i >= 0; i--)
		{
			RobotomyRequestForm		rrf("Reporter");

			workers[i]->signForm(rrf);
			workers[i]->executeForm(rrf);
		}

		std::cout << std::endl;
		std::cout << "Presidential Pardon Form cases: ";
		PresidentialPardonForm		ppf("Cookies");
		std::cout << ppf << std::endl;
		for (int i = 15; i >= 0; i--)
		{
			PresidentialPardonForm	ppf("Cookies");

			workers[i]->signForm(ppf);
			workers[i]->executeForm(ppf);
		}

		for (int i = 0; i <= 15; i++)
			delete workers[i];
	}
}
