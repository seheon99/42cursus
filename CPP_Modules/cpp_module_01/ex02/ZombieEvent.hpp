/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:10:02 by seyu              #+#    #+#             */
/*   Updated: 2021/03/23 18:16:09 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

# include "Zombie.hpp"

class	ZombieEvent
{
private:
	std::string			zombie_type;
	static std::string	*name_pool;
public:
	int		setZombieType(std::string zombie_type);
	int		randomZombieType();
	Zombie*	newZombie(std::string zombie_name);
};

#endif
