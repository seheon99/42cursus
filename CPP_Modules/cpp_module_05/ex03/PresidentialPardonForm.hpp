/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 00:09:19 by seyu              #+#    #+#             */
/*   Updated: 2021/04/11 00:14:50 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class	PresidentialPardonForm : public Form
{
public:
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	virtual ~PresidentialPardonForm() throw();

	PresidentialPardonForm&	operator=(const PresidentialPardonForm& other);

	virtual bool	execute(const Bureaucrat& executer) const;
private:
	PresidentialPardonForm();
	const std::string	_target;
};

#endif
