/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 00:10:10 by seyu              #+#    #+#             */
/*   Updated: 2021/04/11 00:54:21 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
		: Form("Presidential Pardon Form", 25, 5)
		, _target(std::string())
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
		: Form("Presidential Pardon Form", 25, 5)
		, _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
		: Form("Presidential Pardon Form", 25, 5)
		, _target(other._target)
{}

PresidentialPardonForm::~PresidentialPardonForm() throw()
{}

PresidentialPardonForm&
	PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	Form::operator=(other);
	return (*this);
}

bool
	PresidentialPardonForm::execute(const Bureaucrat& executer) const
{
	Form::execute(executer);
	std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
	return (true);
}
