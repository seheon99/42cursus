/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 21:46:16 by seyu              #+#    #+#             */
/*   Updated: 2021/04/12 22:24:31 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "C.hpp"

C::C() {}
C::C(const C& other) { *this = other; }
C::~C() {}

C&	C::operator=(const C& other) { (void)other; return (*this); }