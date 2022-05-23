/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_benchmark.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 22:58:51 by seyu              #+#    #+#             */
/*   Updated: 2021/07/09 17:27:40 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "test_macro.hpp"

#ifdef STL
# include <vector>
# define NAMESPACE std
#else
# include "vector.hpp"
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
	NAMESPACE::vector<int>	vec;

	for (int itr = 0; itr < TEST_OPT_NUM / 10; itr++)
		vec.push_back(std::rand());
	for (int itr = 0; itr < TEST_OPT_NUM / 10; itr++)
		vec.erase(vec.begin());

	return (0);
}
