/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 02:20:44 by seyu              #+#    #+#             */
/*   Updated: 2021/04/14 13:48:25 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

#include <vector>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <set>

#include "easyfind.hpp"

template<typename T>
static void
	test(T& container, std::string typeName, int min, int max, int target)
{
	typename T::iterator	result;

	std::cout << min << " <= random elements <= " << max << std::endl;
	std::cout << "Target number is " << target << std::endl;

	if (max < min || target < min || target > max)
	{
		std::cout << "Impossible condition." << std::endl;
		return ;
	}

	std::cout << typeName << " is :";
	for (int i = 0; i < max - min; i++)
	{
		int	randomData = std::rand() % (max - min + 1) + min;

		container.push_back(randomData);
		std::cout << " [" << randomData << "]";
	}
	std::cout << std::endl;
	result = easyfind(container, target);
	if (result == container.end())
		std::cout << "Element not found" << std::endl;
	else
		std::cout << "Element found successfully" << std::endl;
}

int	main(void)
{
	std::srand(time(NULL));

	std::vector<int>	vec;
	test(vec, "Vector", 10, 30, 20);
	std::cout << std::endl;

	std::deque<int>		deq;
	test(deq, " Deque", 20, 40, 30);
	std::cout << std::endl;

	std::list<int>		lst;
	test(lst, "  List", 30, 50, 40);
	std::cout << std::endl;

	std::set<int>		set;
	std::cout << "40 <= random elements <= 60" << std::endl;
	std::cout << "Target number is 50" << std::endl;
	std::cout << "   Set is :";
	for (int i = 40; i < 60; i++)
	{
		int	randomData;

		randomData = std::rand() % 21 + 40;
		set.insert(i);
		std::cout << " [" << randomData << "]";
	}
	std::cout << std::endl;
	if (easyfind(set, 50) == set.end())
		std::cout << "Element not found" << std::endl;
	else
		std::cout << "Element found successfully" << std::endl;

	return (0);
}
