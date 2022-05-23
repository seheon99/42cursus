/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 03:25:41 by seyu              #+#    #+#             */
/*   Updated: 2021/04/08 04:40:06 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
#include "Stranger.hpp"

int	main()
{
	Sorcerer	robert("Robert", "the Magnificent");

	Victim		jim("Jimmy");
	Peon		joe("Joe");
	Stranger	str("Str");
	Stranger	strstr("strstr");

	std::cout << robert << jim << joe << str << strstr;
	strstr = str;
	std::cout << strstr;

	robert.polymorph(jim);
	robert.polymorph(joe);
	robert.polymorph(str);

	return (0);
}
