/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 04:44:16 by seyu              #+#    #+#             */
/*   Updated: 2021/03/24 04:48:41 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	display_using_pointer(std::string *ptr)
{
	std::cout << *ptr << std::endl;
	return (0);
}

int	display_using_reference(std::string &ptr)
{
	std::cout << ptr << std::endl;
	return (0);
}

int	main(void)
{
	std::string	brain("HI THIS IS BRAIN");

	display_using_pointer(&brain);
	display_using_reference(brain);
	return (0);
}
