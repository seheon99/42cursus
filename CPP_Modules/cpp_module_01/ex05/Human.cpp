/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 05:06:17 by seyu              #+#    #+#             */
/*   Updated: 2021/03/25 17:18:01 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

const Brain*
	Human::identify() const
{
	return (_brain.identify());
}

const Brain&
	Human::getBrain() const
{
	return (_brain);
}
