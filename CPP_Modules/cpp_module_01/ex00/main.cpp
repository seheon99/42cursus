/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 00:13:14 by seyu              #+#    #+#             */
/*   Updated: 2021/03/25 16:37:15 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

static Pony
	*ponyOnTheHeap(void)
{
	Pony	*pony = new Pony("Heap");

	pony->print_infos();
	std::cout << "Heap Pony address in ponyOnTheHeap function: " << pony << std::endl;
	return (pony);
}

static Pony
	ponyOnTheStack(void)
{
	Pony	pony = Pony("Stack");

	pony.print_infos();
	std::cout << "Stack pony address in ponyOnTheStack function: " << &pony << std::endl;
	return (pony);
}

int	main(void)
{
	std::srand(std::time(NULL));

	Pony	*heap_pony;
	heap_pony = ponyOnTheHeap();
	std::cout << "Heap pony address in main function = " << heap_pony << std::endl;
	delete heap_pony;

	Pony	stack_pony;
	stack_pony = ponyOnTheStack();
	std::cout << "Heap pony address in main function = " << &stack_pony << std::endl;
	return (0);
}
