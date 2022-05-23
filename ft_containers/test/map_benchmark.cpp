/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_benchmark.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 22:58:51 by seyu              #+#    #+#             */
/*   Updated: 2021/07/09 17:03:10 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "test_macro.hpp"

#ifdef STL
# include <map>
# define NAMESPACE std
#else
# include "map.hpp"
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
	NAMESPACE::map<int, int>	m;

	for (int itr = 0; itr < TEST_OPT_NUM; itr++)
		m.insert(NAMESPACE::make_pair(std::rand(), itr));
	for (int itr = 0; itr < TEST_OPT_NUM; itr++)
	 	m.erase(m.begin());

	return (0);
}
