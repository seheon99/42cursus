/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:59:42 by seyu              #+#    #+#             */
/*   Updated: 2021/04/15 04:20:09 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _capacity(0), _size(0), _numbers() {}

Span::Span(unsigned int n) : _capacity(n), _size(0), _numbers() {}

Span::Span(const Span& other) : _capacity(other._capacity), _size(other._size), _numbers(other._numbers) {}

Span::~Span() {}

const char*
	Span::AlreadyFullException::what() const throw()
{
	return ("This span is already full");
}

const char*
	Span::NotEnoughNumbersException::what() const throw()
{
	return ("Not enough numbers in this span");
}

Span&
	Span::operator=(const Span& other)
{
	_capacity = other._capacity;
	_size = other._size;
	_numbers = other._numbers;
	return (*this);
}

void
	Span::addNumber(int n)
{
	if (_size >= _capacity)
		throw AlreadyFullException();
	_numbers.insert(n);
	_size++;
}

int	Span::shortestSpan(void) const
{
	if (_size < 2)
		throw NotEnoughNumbersException();

	std::multiset<int>::iterator	small;
	std::multiset<int>::iterator	big;
	int	diffMin;

	diffMin = *(_numbers.rbegin());
	small = _numbers.begin();
	big = ++_numbers.begin();
	while (big != _numbers.end() && diffMin > 0)
	{
		diffMin = std::min(diffMin, *big - *small);
		big++;
		small++;
	}
	return (diffMin);
}

int	Span::longestSpan(void) const
{
	if (_size < 2)
		throw NotEnoughNumbersException();

	int	min = *(_numbers.begin());
	int	max = *(_numbers.rbegin());

	return (max - min);
}

std::ostream&
	Span::print(std::ostream& out) const
{
	std::multiset<int>::iterator	itr;
	int 							count = -1;
	static const int				numPrint = 10;

	itr = _numbers.begin();
	while (itr != _numbers.end() && ++count < numPrint - 1)
	{
		out << "[" << *itr << "]";
		if (++itr == _numbers.end())
			break ;
		out << ", ";
	}
	if (count == numPrint - 1)
		out << "..., [" << *(_numbers.rbegin()) << "]";
	return (out);
}

std::ostream&
	operator<<(std::ostream& out, const Span& self)
{
	return (self.print(out));
}
