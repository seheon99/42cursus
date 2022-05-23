/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 23:54:57 by seyu              #+#    #+#             */
/*   Updated: 2021/04/11 00:54:31 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
		: Form("Robotomy Request Form", 72, 45),
		_target(std::string())
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
		: Form("Robotomy Request Form", 72, 45),
		_target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
		: Form("Robotomy Request Form", 72, 45),
		_target(other._target)
{}

RobotomyRequestForm::~RobotomyRequestForm() throw()
{}

RobotomyRequestForm&
	RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	Form::operator=(other);
	return (*this);
}

bool
	RobotomyRequestForm::execute(const Bureaucrat& executer) const
{
	Form::execute(executer);
	std::cout << "* Drrrr Brrrr Drriooorrrrr *" << std::endl;
	if (std::rand() % 2 == 0)
	{
		std::cout << _target << " has been robotomized successfully" << std::endl;
		return (true);
	}
	else
	{
		std::cout << "Failed to robotomize " << _target << "..." << std::endl;
		return (false);
	}
}
