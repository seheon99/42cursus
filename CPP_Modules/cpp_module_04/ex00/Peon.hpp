/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 18:34:25 by seyu              #+#    #+#             */
/*   Updated: 2021/04/08 04:41:39 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP

# include "Victim.hpp"

class	Peon : public Victim
{
public:
	Peon(std::string name);
	Peon(Peon const& obj);
	~Peon();

	Peon&	operator=(Peon const& other);

	virtual void	getPolymorphed() const;
protected:
	Peon();
};

#endif
