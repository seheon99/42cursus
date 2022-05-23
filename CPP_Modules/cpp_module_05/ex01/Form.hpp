/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 18:34:47 by seyu              #+#    #+#             */
/*   Updated: 2021/04/10 23:31:48 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <ostream>

class	Form;

# include "Bureaucrat.hpp"

class	Form
{
public:
	Form(std::string name, int signGrade, int execGrade);
	Form(const Form& other) throw();
	~Form() throw();

	class	GradeTooHighException : public std::exception
	{
	public:
		const char*	what() const throw();
	};

	class	GradeTooLowException : public std::exception
	{
	public:
		const char*	what() const throw();
	};

	class	AlreadySignedException : public std::exception
	{
	public:
		const char*	what() const throw();
	};

	Form&	operator=(const Form& other) throw();

	bool				beSigned(const Bureaucrat& worker);

	std::string			getName() const throw();
	int					getSignGrade() const throw();
	int					getExecGrade() const throw();
	bool				getSigned() const throw();
private:
	Form() throw();

	const std::string	_name;
	const int			_signGrade;
	const int			_execGrade;
	bool				_signed;
};

std::ostream&	operator<<(std::ostream& out, const Form& self);

#endif
