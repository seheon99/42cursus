/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:06:09 by seyu              #+#    #+#             */
/*   Updated: 2021/03/24 04:23:29 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class	Zombie
{
private:
	std::string	type;
	std::string	name;
	std::string	message;
public:
	Zombie();
	Zombie(std::string type, std::string name);

	int	announce();
};

#endif
