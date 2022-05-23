/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Literal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 02:23:04 by seyu              #+#    #+#             */
/*   Updated: 2021/04/12 16:54:11 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LITERAL_HPP
# define LITERAL_HPP

# include <ostream>

class	Literal
{
public:
	Literal();
	Literal(const Literal& other);
	~Literal();

	operator char();
	operator int();
	operator float();
	operator double();

	Literal&	operator=(const Literal& other);

	void		setChar(char value);
	void		setInt(int value);
	void		setFloat(float value);
	void		setDouble(double value);

	bool		isCharImpossible();
	void		setCharImpossible();
	void		unsetCharImpossible();
	bool		isIntImpossible();
	void		setIntImpossible();
	void		unsetIntImpossible();
	bool		isFloatImpossible();
	void		setFloatImpossible();
	void		unsetFloatImpossible();

private:
	char		_charValue;
	int			_intValue;
	float		_floatValue;
	double		_doubleValue;

	bool		_charImpossible;
	bool		_intImpossible;
	bool		_floatImpossible;
};

std::ostream&	operator<<(std::ostream& out, Literal& self);

#endif
