/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 05:28:15 by seyu              #+#    #+#             */
/*   Updated: 2021/04/13 23:58:43 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "whatever.hpp"

template<class T>
void
	proveSwap(T& arg1, T& arg2)
{
	std::cout << "Original values are " << arg1 << " and " << arg2 << std::endl;
	::swap(arg1, arg2);
	std::cout << "Swapped values are " << arg1 << " and " << arg2 << std::endl;
}

template<class T>
void
	proveCompare(T& arg1, T& arg2)
{
	std::cout << "Smaller one is " << ::min(arg1, arg2) << std::endl;
	std::cout << "Bigger one is " << ::max(arg1, arg2) << std::endl;
}

template<class T>
void
	prove(T& arg1, T& arg2)
{
	proveSwap(arg1, arg2);
	proveCompare(arg1, arg2);
	std::cout << std::endl;
}

int	main(void)
{
	std::cout << "==Subject test cases==" << std::endl;
	{
		int a = 2;
		int b = 3;

		::swap(a, b);
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
		std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

		std::string c = "chaine1";
		std::string d = "chaine2";

		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
		std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
	}

	std::cout << std::endl;
	std::cout << "==My test cases==" << std::endl;
	{
		int			intOne = 1, intTwo = 2;
		prove(intOne, intTwo);

		double		doubleOne = 4.2, doubleTwo = 42.42;
		prove(doubleOne, doubleTwo);

		std::string	stringOne = "string One", stringTwo = "string Two";
		prove(stringOne, stringTwo);

		int		sameOne = 4, sameTwo = 4;
		std::cout << "Values address:" << std::endl;
		std::cout << &sameOne << std::endl;
		std::cout << &sameTwo << std::endl;
		std::cout << "min result: " << &min(sameOne, sameTwo) << std::endl;
		std::cout << "max result: " << &max(sameOne, sameTwo) << std::endl;
	}
	return (0);
}
