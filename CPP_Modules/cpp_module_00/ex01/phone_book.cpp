/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 04:02:20 by seyu              #+#    #+#             */
/*   Updated: 2021/03/09 16:59:03 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone_book.hpp"

phone_book::phone_book() : num_of_contacts(0) {}
phone_book::~phone_book() {}

static void
	print_under_10(std::string str)
{
	if (str.length() > 10)
		std::cout << str.substr(0, 9) << '.';
	else
		std::cout << std::setw(10) << str;
}

void
	phone_book::print_list()
{
	if (this->num_of_contacts == 0)
	{
		std::cout << "The phone book is empty" << std::endl;
		return ;
	}
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	for (int i = 0; i < this->num_of_contacts; i++)
	{
		std::cout << "|";
		std::cout << std::setw(10) << i + 1;
		std::cout << "|";
		print_under_10(this->contacts[i].get_info(F_FIRST_NAME));
		std::cout << "|";
		print_under_10(this->contacts[i].get_info(F_LAST_NAME));
		std::cout << "|";
		print_under_10(this->contacts[i].get_info(F_NICKNAME));
		std::cout << "|";
		std::cout << std::endl;
	}
}

int	phone_book::add()
{
	int	rtn;
	if (this->num_of_contacts >= 8)
	{
		std::cout << "You cannot save more than 8 contacts" << std::endl;
		return (1);
	}
	rtn = this->contacts[this->num_of_contacts].store_infos();
	switch (rtn)
	{
	case 1:
		std::cout << "Stop ADD command" << std::endl;
		return (rtn);
	case -1:
		std::cout << "Terminate the program" << std::endl;
		return (rtn);
	default:
		this->num_of_contacts++;
		return (0);
	}
}

int	phone_book::search()
{
	std::string	input_line;
	int			index;

	this->print_list();
	std::cout << std::endl;
	std::cout << "Please enter the index you want to search: ";
	getline(std::cin, input_line);
	if (std::cin.good())
	{
		for (int i = 0; true; i++)
		{
			if (isblank(input_line[i]))
				continue ;
			if (input_line[i] == '\0')
				return (0);
			if (i > 0)
				std::cout << "----------------------------------------" << std::endl;
			if (isdigit(input_line[i]) == false)
				break ;
			index = input_line[i] - '0';
			if (index == 0 || index > this->num_of_contacts)
				break ;
			this->contacts[index - 1].print_infos();
		}
	}
	if (std::cin.eof())
		std::cout << std::endl << "EOF encountered" << std::endl;
	else if (std::cin.fail())
		std::cout << "Error: Invalid index number" << std::endl;
	std::cin.clear();
	return (1);
}
