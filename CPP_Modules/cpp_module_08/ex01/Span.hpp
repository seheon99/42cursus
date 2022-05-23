/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:50:22 by seyu              #+#    #+#             */
/*   Updated: 2021/04/15 03:44:20 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <exception>
# include <set>
# include <ostream>

class	Span
{
public:
	Span(unsigned int n);
	Span(const Span& other);
	~Span();

	class	AlreadyFullException : public std::exception {
		virtual const char* what() const throw();
	};

	class	NotEnoughNumbersException : public std::exception {
		virtual const char* what() const throw();
	};

	Span&	operator=(const Span& other);

	void	addNumber(int n);
	int		shortestSpan(void) const;
	int		longestSpan(void) const;

	std::ostream&	print(std::ostream& out) const;
private:
	Span();

	int					_capacity;
	int					_size;
	std::multiset<int>	_numbers;
};

std::ostream&	operator<<(std::ostream& out, const Span& self);

#endif
