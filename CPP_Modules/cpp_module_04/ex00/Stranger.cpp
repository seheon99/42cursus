/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stranger.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 01:04:16 by seyu              #+#    #+#             */
/*   Updated: 2021/04/08 04:41:01 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Stranger.hpp"

Stranger::Stranger()
	: Victim()
{}

Stranger::Stranger(std::string name) : Victim(name)
{
	std::cout << "Hi!" << std::endl;
}

Stranger::Stranger(Stranger const& other)
{
	*this = other;
}

Stranger::~Stranger()
{
	std::cout << "Bye~" << std::endl;
}

Stranger&
	Stranger::operator=(Stranger const& other)
{
	Victim::operator=(other);
	return (*this);
}

void
	Stranger::getPolymorphed() const
{
	std::cout << _name << " has been turned into my friend!" << std::endl;
}
