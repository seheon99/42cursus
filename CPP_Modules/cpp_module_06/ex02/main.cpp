/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 21:48:49 by seyu              #+#    #+#             */
/*   Updated: 2021/04/12 23:54:48 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base
	*generate(void)
{
	int	randomSelect;

	randomSelect = std::rand() % 3;
	if (randomSelect == 0)
		return (new A);
	else if (randomSelect == 1)
		return (new B);
	else
		return (new C);
}

void
	identify_from_pointer(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "This is A class pointer" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "This is B class pointer" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "This is C class pointer" << std::endl;
	else
		std::cout << "This is just Base class pointer" << std::endl;
}

void
	identify_from_reference(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "This is A class reference" << std::endl;
		return ;
	}
	catch (const std::exception& e) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "This is B class reference" << std::endl;
		return ;
	}
	catch (const std::exception& e) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "This is C class reference" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}
	std::cout << "This is just Base class reference" << std::endl;
}

int	main(void)
{
	Base*	randomPointer;

	std::srand(time(NULL));
	randomPointer = generate();
	identify_from_pointer(randomPointer);
	identify_from_reference(*randomPointer);
	delete randomPointer;
	return (0);
}
