/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 04:30:10 by seyu              #+#    #+#             */
/*   Updated: 2021/03/09 16:41:45 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone_book.hpp"
#include "contact.hpp"

int main(void)
{
	std::string	command;
	phone_book	pb;
	int			rtn;

	rtn = 0;
	while (rtn >= 0)
	{
		if (std::cin.eof())
			return (1);
		std::cout << std::endl;
		std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
		if (rtn == 0)
			std::cout << "\033[34m>\033[0m ";
		else
			std::cout << "\033[31m" << rtn << " >\033[0m ";
		getline(std::cin, command);
		for (int i = 0; command[i] != '\0'; i++)
			command[i] = toupper(command[i]);
		if (std::cin.fail() || command == "EXIT")
			return (0);
		else if (command == "ADD")
			rtn = pb.add();
		else if (command == "SEARCH")
			rtn = pb.search();
		else
		{
			std::cout << "crappy: Command not found: " << command << std::endl;
			rtn = 127;
		}
	}
	return (1);
}
