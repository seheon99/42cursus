/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 05:06:13 by seyu              #+#    #+#             */
/*   Updated: 2021/03/25 17:13:16 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

#include <iostream>

int	main(void)
{
	Human	bob;

	std::cout << bob.identify() << std::endl;
	std::cout << bob.getBrain().identify() << std::endl;
}
