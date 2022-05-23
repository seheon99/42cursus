/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_benchmark.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 22:58:51 by seyu              #+#    #+#             */
/*   Updated: 2021/07/09 17:27:49 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "test_macro.hpp"

#ifdef STL
# include <set>
# define NAMESPACE std
#else
# include "set.hpp"
# define NAMESPACE ft
#endif

#ifndef SEED
# define SEED (std::time(NULL))
#endif

int	main(void)
{
	std::srand(SEED);

	/* ---------------------------------------- */
	/*            Optimization Test             */
	/* ---------------------------------------- */
	NAMESPACE::set<int>	s;

	for (int itr = 0; itr < TEST_OPT_NUM; itr++)
		s.insert(std::rand());
	for (int itr = 0; itr < TEST_OPT_NUM; itr++)
	 	s.erase(s.begin());

	return (0);
}
