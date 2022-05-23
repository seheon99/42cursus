/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 03:21:34 by seyu              #+#    #+#             */
/*   Updated: 2021/04/11 03:52:01 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat	boss("Boss", 1);
	Bureaucrat	employee("Employee", 50);
	Bureaucrat	intern("Intern", 150);

	std::cout << "---Check all functions are valid" << std::endl;
	{
		std::cout << boss << std::endl;
		std::cout << employee << std::endl;
		std::cout << intern << std::endl;
		employee.upgrade();
		std::cout << "Upgraded employee -> " << employee << std::endl;
		employee.downgrade();
		std::cout << "Downgraded employee -> " << employee << std::endl;
		std::cout << "Bigger one (boss vs intern) -> " << (boss > intern ? boss : intern) << std::endl;
	}
	std::cout << "---Check all exceptions are valid" << std::endl;
	{
		Bureaucrat	*exceptionMaker = nullptr;

		try
		{
			std::cout << "0 Grade bureaucrat -> ";
			exceptionMaker = new Bureaucrat("Name", 0);
			std::cout << exceptionMaker << std::endl;
			delete exceptionMaker;
		}
		catch (const std::exception& e)
		{
			std::cout << "0 Grade bureaucrat cannot be constructed because " << e.what() << std::endl;
		}
		try
		{
			std::cout << "200 Grade bureaucrat -> ";
			exceptionMaker = new Bureaucrat("Name", 200);
			std::cout << exceptionMaker << std::endl;
			delete exceptionMaker;
		}
		catch (const std::exception& e)
		{
			std::cout << "200 Grade bureaucrat cannot be constructed because " << e.what() << std::endl;
		}
		try
		{
			std::cout << "Upgraded boss -> ";
			boss.upgrade();
			std::cout << boss << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << "Boss cannot upgrade because " << e.what() << std::endl;
		}
		try
		{
			std::cout << "Downgraded intern -> ";
			intern.downgrade();
			std::cout << intern << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << "Intern cannot downgrade because " << e.what() << std::endl;
		}
	}
}
