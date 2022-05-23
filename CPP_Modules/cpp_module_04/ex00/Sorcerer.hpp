/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 14:55:29 by seyu              #+#    #+#             */
/*   Updated: 2021/04/08 04:41:31 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <string>
# include <ostream>

# include "Victim.hpp"

class	Sorcerer
{
public:
	Sorcerer(std::string name, std::string title);
	Sorcerer(Sorcerer const& obj);
	~Sorcerer();

	Sorcerer&		operator=(Sorcerer const& other);

	std::ostream&	introduceSelf(std::ostream& out) const;
	void			polymorph(Victim const& target) const;
protected:
	Sorcerer();
private:
	std::string	_name;
	std::string	_title;
};

std::ostream&		operator<<(std::ostream& out, Sorcerer const& self);

#endif
