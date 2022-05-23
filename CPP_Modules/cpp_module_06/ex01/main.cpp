/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 18:08:55 by seyu              #+#    #+#             */
/*   Updated: 2021/04/12 18:54:28 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

#include "Data.hpp"

int	main(void)
{
	std::srand(time(NULL));

	void*	raw_data;
	Data*	data;

	raw_data = serialize();
	data = deserialize(raw_data);
	std::cout << data->s1 << std::endl
			<< data->n << std::endl
			<< data->s2 << std::endl;

	delete[] reinterpret_cast<char*>(raw_data);
	delete data;

	return (0);
}
