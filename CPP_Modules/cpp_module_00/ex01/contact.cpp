/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 03:23:08 by seyu              #+#    #+#             */
/*   Updated: 2021/03/09 16:52:03 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone_book.hpp"

contact::contact() {}
contact::~contact() {}

std::string	contact::_field_names[11] = {
	std::string("first name"),
	std::string("last name"),
	std::string("nickname"),
	std::string("login"),
	std::string("postal address"),
	std::string("email address"),
	std::string("phone number"),
	std::string("birthday date"),
	std::string("favorite meal"),
	std::string("underwear color"),
	std::string("darkest secret"),
};

int	contact::store_infos()
{
	for (int i = 0; i < 11; i++)
	{
		std::cout << this->_field_names[i] << ": ";
		getline(std::cin, this->_infos[i]);
		if (std::cin.fail() == true)
		{
			std::cin.clear();
			std::cout << std::endl;
			std::cout << "EOF encountered" << std::endl;
			return (-1);
		}
	}
	return (0);
}

void
	contact::print_infos()
{
	for (int i = 0; i < 11; i++)
	{
		std::cout << std::setw(15) << this->_field_names[i] << ": ";
		std::cout << this->_infos[i];
		std::cout << std::endl;
	}
}

std::string
	contact::get_info(int index)
{
	return (this->_infos[index]);
}
