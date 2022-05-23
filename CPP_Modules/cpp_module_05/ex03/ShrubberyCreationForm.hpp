/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 22:40:40 by seyu              #+#    #+#             */
/*   Updated: 2021/04/11 00:14:24 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"

class	ShrubberyCreationForm : public Form
{
public:
	ShrubberyCreationForm(std::string const& target);
	ShrubberyCreationForm(ShrubberyCreationForm const& other);
	virtual ~ShrubberyCreationForm() throw();

	class	CannotOpenFileException : public std::exception
	{
	public:
		const char* what() const throw();
	};

	ShrubberyCreationForm&	operator=(ShrubberyCreationForm const& other) throw();

	virtual bool	execute(const Bureaucrat& executer) const;
private:
	ShrubberyCreationForm() throw();
	static const std::string	_trees[4];
	const std::string 			_target;
};

#endif
