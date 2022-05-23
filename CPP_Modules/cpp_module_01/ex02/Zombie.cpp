/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:17:35 by seyu              #+#    #+#             */
/*   Updated: 2021/03/24 04:38:11 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <iostream>
#include <cstdlib>

static std::string
	make_some_message(std::string original_message)
{
	std::string	return_message = "";
	int			length;

	return_message = "";
	for (unsigned long ch_itr = 0; ch_itr < original_message.length(); ch_itr++)
	{
		length = std::rand() % 5 + 1;
		for (int copy_itr = 0; copy_itr < length; copy_itr++)
			return_message += original_message.at(ch_itr);
	}
	return (return_message);
}

Zombie::Zombie()
	: type("noType"), name("noName"), message(make_some_message("candy."))
{}
Zombie::Zombie(std::string type, std::string name)
	: type(type), name(name), message(make_some_message("candy."))
{}

int
	Zombie::announce(void)
{
	if (this->name.empty() == true || this->type.empty() == true)
		return (1);
	std::cout << this->name << " (" << this->type << "): " << this->message << std::endl;
	return (0);
}
