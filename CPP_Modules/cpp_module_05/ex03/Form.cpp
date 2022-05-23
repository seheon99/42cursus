/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 18:44:50 by seyu              #+#    #+#             */
/*   Updated: 2021/04/11 04:04:47 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() throw()
		: _name(std::string()),
		_signGrade(Bureaucrat::_gradeMax),
		_execGrade(Bureaucrat::_gradeMax)
{}

Form::Form(std::string name, int signGrade, int execGrade)
		: _name(name), _signGrade(signGrade), _execGrade(execGrade), _signed(false)
{
	if (_signGrade < Bureaucrat::_gradeMax || _execGrade < Bureaucrat::_gradeMax)
		throw GradeTooHighException();
	if (_signGrade > Bureaucrat::_gradeMin || _execGrade > Bureaucrat::_gradeMin)
		throw GradeTooLowException();
}

Form::Form(const Form& other) throw()
		: _name(other._name),
		_signGrade(other._signGrade),
		_execGrade(other._execGrade),
		_signed(other._signed)
{}

Form::~Form() throw() {}

const char*
	Form::GradeTooHighException::what() const throw()
{
	return ("The grade is too high.");
}

const char*
	Form::GradeTooLowException::what() const throw()
{
	return ("The grade is too low.");
}

const char*
	Form::AlreadySignedException::what() const throw()
{
	return ("The form is already signed.");
}

const char*
	Form::NotSignedException::what() const throw()
{
	return ("The form is not signed.");
}

Form&
	Form::operator=(const Form& other) throw()
{
	if (this == &other)
		return (*this);
	_signed = other._signed;
	return (*this);
}

void
	Form::beSigned(const Bureaucrat& worker)
{
	if (worker < _signGrade)
		throw GradeTooLowException();
	else if (_signed == true)
		throw AlreadySignedException();
	_signed = true;
}

bool
	Form::execute(const Bureaucrat& executer) const
{
	if (executer < _execGrade)
		throw GradeTooLowException();
	else if (_signed == false)
		throw NotSignedException();
	return (true);
}

std::string
	Form::getName() const throw()
{
	return (_name);
}

int	Form::getSignGrade() const throw()
{
	return (_signGrade);
}

int Form::getExecGrade() const throw()
{
	return (_execGrade);
}

bool
	Form::getSigned() const throw()
{
	return (_signed);
}

std::ostream&
	operator<<(std::ostream& out, const Form& self)
{
	out << self.getName() << (self.getSigned() ? " [v] " : " [x] ")
		<< "(Grade " << self.getSignGrade() << " to sign, "
		<< "Grade " << self.getExecGrade() << " to execute)";
	return (out);
}
