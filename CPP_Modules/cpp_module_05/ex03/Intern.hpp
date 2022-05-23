/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 01:05:27 by seyu              #+#    #+#             */
/*   Updated: 2021/04/11 04:14:43 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"

class	Intern
{
public:
	Intern();
	Intern(const Intern& other);
	~Intern();

	Intern&	operator=(const Intern& other);

	Form*	makeForm(std::string formName, std::string formTarget) const;
private:
	static const std::string	_formNames[3][2];
	static Form*				(*_forms[3])(const std::string& target);
};

Form*	makeShrubberyCreationForm(const std::string& target);
Form*	makeRobotomyRequestForm(const std::string& target);
Form*	makePresidentialPardonForm(const std::string& target);

#endif
