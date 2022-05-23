/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 23:50:45 by seyu              #+#    #+#             */
/*   Updated: 2021/03/25 16:38:10 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>

Pony::Pony() : height(0), weight(0), age(0), name("")
{
	std::cout << "A new pony is born" << std::endl;
}

Pony::Pony(std::string pony_name) : name(pony_name)
{
	std::cout << this->name << " is born" << std::endl;
	this->height = std::rand() % 10 + 80;
	this->weight = std::rand() % 5 + 20;
	this->age = std::rand() % 2 + 1;
}

Pony::~Pony(void)
{
	std::cout << this->name << " died" << std::endl;
}

int	Pony::print_infos(void)
{
	std::cout << "This is about a pony named " << this->name << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << this->age << " yaers old" << std::endl;
	std::cout << "Height: " << this->height << "cm" << std::endl;
	std::cout << "Weight: " << this->weight << "kg" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	return (0);
}
