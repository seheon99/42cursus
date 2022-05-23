/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 18:22:29 by seyu              #+#    #+#             */
/*   Updated: 2021/04/08 01:26:57 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <string>
# include <ostream>

class	Victim
{
public:
	Victim(std::string name);
	Victim(Victim const& obj);
	~Victim();

	Victim&			operator=(Victim const& other);

	std::ostream&	introduceSelf(std::ostream& out) const;
	virtual void	getPolymorphed() const;
protected:
	Victim();

	std::string	_name;
};

std::ostream&	operator<<(std::ostream& out, Victim const& self);

#endif
