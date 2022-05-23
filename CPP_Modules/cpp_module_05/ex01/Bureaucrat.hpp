/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 06:12:31 by seyu              #+#    #+#             */
/*   Updated: 2021/04/10 23:30:29 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <ostream>

class	Bureaucrat;

# include "Form.hpp"

class	Bureaucrat
{
public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& other) throw();
	~Bureaucrat() throw();

	class	GradeTooHighException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	private:
		static const std::string	_comment;
	};
	class	GradeTooLowException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};

	operator int() const throw();

	Bureaucrat&			operator=(const Bureaucrat& other) throw();
	bool				operator<=(const int& grade) const throw();
	bool				operator<(const int& grade) const throw();
	bool				operator>=(const int& grade) const throw();
	bool				operator>(const int& grade) const throw();

	bool				signForm(Form& form);
	int					upgrade();
	int					downgrade();

	std::string			getName() const throw();
	int					getGrade() const throw();

	static const int	_gradeMax;
	static const int	_gradeMin;
private:
	Bureaucrat() throw();

	const std::string	_name;
	int					_grade;
};

std::ostream&			operator<<(std::ostream& out, const Bureaucrat& self);

#endif
