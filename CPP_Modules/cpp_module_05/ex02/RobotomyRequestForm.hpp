/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 23:53:08 by seyu              #+#    #+#             */
/*   Updated: 2021/04/11 00:14:55 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"

class	RobotomyRequestForm : public Form
{
public:
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	virtual ~RobotomyRequestForm() throw();

	RobotomyRequestForm&	operator=(const RobotomyRequestForm& other);

	virtual bool	execute(const Bureaucrat& executer) const;
private:
	RobotomyRequestForm();
	const std::string	_target;
};

#endif
