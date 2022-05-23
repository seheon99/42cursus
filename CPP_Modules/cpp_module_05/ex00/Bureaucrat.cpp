/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 06:19:33 by seyu              #+#    #+#             */
/*   Updated: 2021/04/11 03:54:08 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	const Bureaucrat::_gradeMax = 1;
int	const Bureaucrat::_gradeMin = 150;

Bureaucrat::Bureaucrat() throw()
		: _name(std::string()), _grade(_gradeMin)
{}

Bureaucrat::Bureaucrat(std::string name, int grade)
		: _name(name), _grade(grade)
{
	if (_grade < _gradeMax)
		throw GradeTooHighException();
	else if (_grade > _gradeMin)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) throw()
		: _name(other._name), _grade(other._grade)
{}

Bureaucrat::~Bureaucrat() throw()
{}

const char*
	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("The grade of the bureaucrat is too high");
}

const char*
	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("The grade of the bureaucrat is too low");
}

Bureaucrat::operator int() const throw()
{
	return (_grade);
}

Bureaucrat&
	Bureaucrat::operator=(const Bureaucrat& other) throw()
{
	if (this == &other)
		return (*this);
	_grade = other._grade;
	return (*this);
}

bool
	Bureaucrat::operator<=(const int& grade) const throw()
{
	return (_grade >= grade);
}

bool
	Bureaucrat::operator<(const int& grade) const throw()
{
	return (_grade > grade);
}

bool
	Bureaucrat::operator>=(const int& grade) const throw()
{
	return (_grade <= grade);
}

bool
	Bureaucrat::operator>(const int& grade) const throw()
{
	return (_grade < grade);
}

int	Bureaucrat::downgrade()
{
	if (_grade == _gradeMin)
		throw GradeTooLowException();
	return (++_grade);
}

std::string
	Bureaucrat::getName() const throw()
{
	return (_name);
}

int	Bureaucrat::getGrade() const throw()
{
	return (_grade);
}

int	Bureaucrat::upgrade()
{
	if (_grade == _gradeMax)
		throw GradeTooHighException();
	return (--_grade);
}

std::ostream&
	operator<<(std::ostream& out, const Bureaucrat& self)
{
	out << self.getName() << " (bureaucrat, Grade " << self.getGrade() << ")";
	return (out);
}
