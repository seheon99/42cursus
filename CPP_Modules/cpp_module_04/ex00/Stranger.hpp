/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stranger.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 01:03:23 by seyu              #+#    #+#             */
/*   Updated: 2021/04/08 04:41:21 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRANGER_HPP
# define STRANGER_HPP

# include <string>
# include <ostream>

# include "Victim.hpp"

class	Stranger : public Victim
{
public:
	Stranger(std::string name);
	Stranger(Stranger const& other);
	~Stranger();

	Stranger&	operator=(Stranger const& other);

	virtual void	getPolymorphed() const;
protected:
	Stranger();
};

#endif
