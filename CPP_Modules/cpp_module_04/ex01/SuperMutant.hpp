/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 04:55:38 by seyu              #+#    #+#             */
/*   Updated: 2021/04/06 07:43:35 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

# include "Enemy.hpp"

class	SuperMutant : public Enemy
{
public:
	SuperMutant();
	SuperMutant(SuperMutant const& other);
	virtual ~SuperMutant();

	SuperMutant&	operator=(SuperMutant const& other);

	virtual void	takeDamage(int damage);
private:
};

#endif
