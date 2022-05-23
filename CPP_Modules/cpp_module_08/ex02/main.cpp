/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 04:43:10 by seyu              #+#    #+#             */
/*   Updated: 2021/04/15 06:03:18 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <deque>
#include <string>

#include "MutantStack.hpp"

template<typename T>
static void
	testStack(std::stack<T> stack)
{
	std::cout << "stack size = " << stack.size() << std::endl;
	std::cout << "stack empty = " << (stack.empty() ? "true" : "false") << std::endl;

	std::cout << "stack push:";
	for (int i = 0; i < 10; i++)
	{
		int	randomNumber = std::rand() % 9 + 1;

		std::cout << " " << randomNumber;
		stack.push(randomNumber);
	}
	std::cout << std::endl;

	std::cout << "stack size = " << stack.size() << std::endl;
	std::cout << "stack empty = " << (stack.empty() ? "true" : "false") << std::endl;

	std::cout << "stack pop:";
	while (stack.empty() == false)
	{
		std::cout << " " << stack.top();
		stack.pop();
	}
	std::cout << std::endl;

	std::cout << "stack size = " << stack.size() << std::endl;
	std::cout << "stack empty = " << (stack.empty() ? "true" : "false") << std::endl;
	std::cout << std::endl;
}

int main()
{
	std::cout << "==Subject's main==" << std::endl;
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;

		mstack.pop();

		std::cout << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	std::cout << std::endl;
	std::cout << "==My main==" << std::endl;
	{
		std::stack<int>		realStack;
		MutantStack<int>	mutantStack;

		testStack(realStack);
		testStack(mutantStack);
	}
	{
		std::stack<std::string>		realStack;
		MutantStack<std::string>	mutantStack;

		realStack.push("This is real!!!");
		realStack.push("This is real stack.");
		mutantStack.push("Hello, my name is mutantstack.");
		mutantStack.push("Hi, this is mutant stack.");

		std::cout << "Before swap:" << std::endl;
		std::cout << "realStack's top = " << realStack.top() << std::endl;
		std::cout << "mutantStack's top = " << mutantStack.top() << std::endl;

		mutantStack.swap(realStack);

		std::cout << "After swap:" << std::endl;
		std::cout << "realStack's top = " << realStack.top() << std::endl;
		std::cout << "mutantStack's top = " << mutantStack.top() << std::endl;

		mutantStack = realStack;

		std::cout << "mutantStack = realStack" << std::endl;
		std::cout << "realStack's top = " << realStack.top() << std::endl;
		std::cout << "mutantStack's top = " << mutantStack.top() << std::endl;
		std::cout << std::endl;
	}
	{
		MutantStack<int>	mutantStack;

		std::cout << "stack push:";
		for (int i = 0; i < 10; i++)
		{
			int	randomNumber = std::rand() % 9 + 1;

			std::cout << " " << randomNumber;
			mutantStack.push(randomNumber);
		}
		std::cout << std::endl;

		MutantStack<int>::iterator	itr;
		std::cout << "stack iterator:";
		itr = mutantStack.begin();
		while (itr != mutantStack.end())
		{
			std::cout << " " << *itr;
			itr++;
		}
		std::cout << std::endl;

		std::cout << "stack pop:";
		for (int i = 0; i < 10; i++)
		{
			std::cout << " " << mutantStack.top();
			mutantStack.pop();
		}
		std::cout << std::endl;
	}
	return (0);
}
