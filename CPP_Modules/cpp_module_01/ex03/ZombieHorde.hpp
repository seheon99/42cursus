/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:10:03 by seyu              #+#    #+#             */
/*   Updated: 2021/03/24 04:39:12 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

# include "Zombie.hpp"

class	ZombieHorde
{
private:
	int		num_of_zombies;
	Zombie	*zombies;
public:
	ZombieHorde(int num_of_zombies);
	~ZombieHorde();

	int	announce();
};

#endif
