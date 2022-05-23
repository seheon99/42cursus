/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 01:45:47 by seyu              #+#    #+#             */
/*   Updated: 2021/04/11 04:18:17 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

#include "Intern.hpp"

int	main(void)
{
	std::srand(std::time(NULL));
	std::cout << "---Check all funtions are valid" << std::endl;
	{
		Intern		intern;
		std::string	formSets[][2] = {
			{"shrubbery creation", "42seoul"},
			{"shrubbery creation form", "42seoul"},
			{"Shrubbery Creation", "42seoul"},
			{"Shrubbery Creation Form", "42seoul"},
			{"ShRuBbErY CrEaTiOn FoRm", "42seoul"},
			{"robotomy request", "coder"},
			{"robotomy request form", "coder"},
			{"Robotomy Request", "coder"},
			{"Robotomy Request Form", "coder"},
			{"RoBoToMy ReQuEsT FoRm", "coder"},
			{"presidential pardon", "cookies"},
			{"presidential pardon form", "cookies"},
			{"Presidential Pardon", "cookies"},
			{"Presidential Pardon Form", "cookies"},
			{"PrEsIdEnTiAl PaRdOn FoRm", "cookies"},
		};

		for (size_t i = 0; i < sizeof(formSets) / sizeof(std::string) / 2; i++)
		{
			delete intern.makeForm(formSets[i][0], formSets[i][1]);
		}
	}
	std::cout << std::endl;
	std::cout << "---Check all exceptions are valid" << std::endl;
	{
		Intern		intern;
		Form		*form;
		std::string	formSets[][2] = {
			{"shrubery creation", "42seoul"},
			{"robotomory request", "coder"},
			{"president pardon", "cookies"},
			{"Random Forms", "Random Target"},
			{"", ""},
			{std::string(), std::string()},
		};

		for (size_t i = 0; i < sizeof(formSets) / sizeof(std::string) / 2; i++)
		{
			if ((form = intern.makeForm(formSets[i][0], formSets[i][1])) != nullptr)
			{
				std::cout << *form << std::endl;
				delete form;
			}
		}
	}
}
