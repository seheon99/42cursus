/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 21:38:11 by seyu              #+#    #+#             */
/*   Updated: 2021/04/11 03:55:03 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat	employee("Employee", 10);
	Bureaucrat	boss("Boss", 1);

	std::cout << "Our new bureaucrats:" << std::endl;
	std::cout << boss << std::endl << employee << std::endl;

	Form	iPhone("Buy new iPhone", 5, 15);

	std::cout << std::endl;
	std::cout << "Our new forms:" << std::endl;
	std::cout << iPhone << std::endl;

	std::cout << std::endl;
	std::cout << "---Check all funtions are valid" << std::endl;
	{
		std::cout << "Boss try to sign the form, " << iPhone << std::endl;
		boss.signForm(iPhone);
		std::cout << "Employee try to sign the form, " << iPhone << std::endl;
		employee.signForm(iPhone);
	}
	std::cout << std::endl;
	std::cout << "---Check all exceptions are valid" << std::endl;
	{
		Form	*iPad = nullptr;
		try
		{
			iPad = new Form("Buy new iPad", 0, 5);
			delete iPad;
		}
		catch (const std::exception& e)
		{
			std::cout << "new Form(\"Buy new iPad\", 0, 5) cannot be constructed because " << e.what() << std::endl;
		}
		try
		{
			iPad = new Form("Buy new iPad", 10, 200);
			delete iPad;
		}
		catch (const std::exception& e)
		{
			std::cout << "new Form(\"Buy new iPad\", 10, 200) cannot be constructed because " << e.what() << std::endl;
		}
	}
}
