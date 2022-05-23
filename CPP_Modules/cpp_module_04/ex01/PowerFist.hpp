/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 04:36:31 by seyu              #+#    #+#             */
/*   Updated: 2021/04/08 01:18:52 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWERFIST_HPP
# define POWERFIST_HPP

# include "AWeapon.hpp"

class	PowerFist : public AWeapon
{
public:
	PowerFist();
	PowerFist(PowerFist const& other);
	virtual ~PowerFist();

	PowerFist&		operator=(PowerFist const& other);

	virtual void	attack() const;
private:
};

#endif
