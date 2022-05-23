/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 06:17:33 by seyu              #+#    #+#             */
/*   Updated: 2021/04/13 23:59:09 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "iter.hpp"

template<class T>
void
	print(T& elem)
{
	std::cout << " " << elem;
}

int	main(void)
{
	int			intArr[] = {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
	std::string	strArr[] = {"str1", "str2", "str3", "str4", "str5", "str6", "str7", "str8", "str9", "str10"};

	std::cout << "intArr:";
	iter(intArr, 10, print);
	std::cout << std::endl;

	std::cout << "strArr:";
	iter(strArr, 10, print);
	std::cout << std::endl;

	std::cout << "null array:";
	iter(reinterpret_cast<int*>(NULL), 10, print);
	std::cout << std::endl;

	std::cout << "null function:";
	iter(intArr, 10, reinterpret_cast<void(*)(int&)>(NULL));
	std::cout << std::endl;

	return (0);
}
