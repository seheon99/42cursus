/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 13:00:58 by seyu              #+#    #+#             */
/*   Updated: 2021/03/22 16:55:37 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void
	memoryLeak()
{
	std::string	*panther = new std::string("String panther");

	std::cout << *panther << std::endl;
	delete panther;
}
