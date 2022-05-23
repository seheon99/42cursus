/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 18:10:34 by seyu              #+#    #+#             */
/*   Updated: 2021/04/12 18:53:00 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <cstdlib>

#include "Data.hpp"

const char*	alphanumeric = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

void*
	serialize(void)
{
	char	*data = new char[20];

	for (int i = 0; i < 8; i++)
		data[i] = alphanumeric[std::rand() % 62];
	*(reinterpret_cast<int*>(data + 8)) = std::rand();
	for (int i = 12; i < 20; i++)
		data[i] = alphanumeric[std::rand() % 62];
	return ( data);
}

Data*
	deserialize(void *raw)
{
	Data	*rtn = new Data;

	rtn->s1 = std::string(reinterpret_cast<char*>(raw), 8);
	rtn->n = *(static_cast<int*>(raw) + 2);
	rtn->s2 = std::string(reinterpret_cast<char*>(raw) + 12, 8);
	return (rtn);
}
