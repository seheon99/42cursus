/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 05:00:53 by seyu              #+#    #+#             */
/*   Updated: 2021/04/08 01:44:59 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP

# include "Enemy.hpp"

class	RadScorpion : public Enemy
{
public:
	RadScorpion();
	RadScorpion(RadScorpion const& other);
	virtual ~RadScorpion();

	RadScorpion&	operator=(RadScorpion const& other);
private:
};

#endif
