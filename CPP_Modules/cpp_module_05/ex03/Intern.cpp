/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 01:20:41 by seyu              #+#    #+#             */
/*   Updated: 2021/04/11 04:18:37 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include "Intern.hpp"

Intern::Intern()
{}

Intern::Intern(const Intern& other)
{
	*this = other;
}

Intern::~Intern()
{}

Intern&
	Intern::operator=(const Intern& other)
{
	if (this == &other)
		return (*this);
	return (*this);
}

Form*
	Intern::makeForm(std::string formName, std::string formTarget) const
{
	for (size_t i = 0; i < formName.length(); i++)
		formName[i] = tolower(formName[i]);
	for (size_t i = 0; i < sizeof(_formNames) / sizeof(std::string); i++)
	{
		if (formName == _formNames[i / 2][i % 2])
		{
			Form*	newForm = _forms[i / 2](formTarget);

			std::cout << "Intern creates " << *newForm << std::endl;
			return (newForm);
		}
	}
	std::cout << "Intern cannot find the form named " << formName << std::endl;
	return (nullptr);
}

const std::string	Intern::_formNames[3][2] = {
	{"shrubbery creation", "shrubbery creation form"},
	{"robotomy request", "robotomy request form"},
	{"presidential pardon", "presidential pardon form"},
};

Form*				(*Intern::_forms[3])(const std::string& target) = {
	makeShrubberyCreationForm,
	makeRobotomyRequestForm,
	makePresidentialPardonForm,
};

Form*
	makeShrubberyCreationForm(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

Form*
	makeRobotomyRequestForm(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}

Form*
	makePresidentialPardonForm(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}
