/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 08:47:59 by seyu              #+#    #+#             */
/*   Updated: 2021/04/12 23:35:58 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <limits>
#include <cstdlib>
#include <cmath>
#include <cerrno>

#include "Literal.hpp"

enum	type_e {
	CHAR = 0,
	INT,
	FLOAT,
	DOUBLE,
	OTHER
};

type_e
	getType(std::string raw)
{
	if (raw.length() == 0)
		return (type_e(OTHER));
	if (raw.length() == 1)
	{
		if (raw[0] >= '0' && raw[0] <= '9')
			return (type_e(INT));
		return (type_e(CHAR));
	}

	long	l;
	double	d;
	char*	endptr;

	l = strtol(raw.c_str(), &endptr, 10);
	if (endptr[0] == '\0'
			&& l <= std::numeric_limits<int>::max()
			&& l >= std::numeric_limits<int>::min())
		return (type_e(INT));

	d = strtod(raw.c_str(), &endptr);
	if (std::string(endptr) == "f")
	{
		if (std::isinf(d) && errno == ERANGE)
			return (type_e(OTHER));
		else if (std::isinf(d) || std::isnan(d))
			return (type_e(FLOAT));
		else if (d <= std::numeric_limits<float>::max()
				&& d >= -std::numeric_limits<float>::max())
			return (type_e(FLOAT));
		return (type_e(OTHER));
	}
	else if (endptr[0] == '\0')
	{
		if (std::isinf(d) && errno == ERANGE)
			return (type_e(OTHER));
		else if (std::isinf(d) || std::isnan(d))
			return (type_e(DOUBLE));
		return (type_e(DOUBLE));
	}
	return (type_e(OTHER));
}

void
	fromChar(Literal& converted, std::string raw)
{
	char	data;

	data = raw[0];
	converted.setChar(data);
	converted.setInt(static_cast<int>(data));
	converted.setFloat(static_cast<float>(data));
	converted.setDouble(static_cast<double>(data));
}

void
	fromInt(Literal& converted, std::string raw)
{
	long	data;

	data = strtol(raw.c_str(), NULL, 10);
	if (data > std::numeric_limits<int>::max() || data < std::numeric_limits<int>::min())
	{
		converted.setCharImpossible();
		converted.setIntImpossible();
	}
	else if (data > std::numeric_limits<char>::max() || data < std::numeric_limits<char>::min())
	{
		converted.setCharImpossible();
		converted.setInt(data);
	}
	else
	{
		converted.setChar(static_cast<char>(data));
		converted.setInt(data);
	}
	converted.setFloat(static_cast<float>(data));
	converted.setDouble(static_cast<double>(data));
}

void
	fromFloat(Literal& converted, std::string raw)
{
	float	data;

	if (raw == "-inff")
	{
		converted.setCharImpossible();
		converted.setIntImpossible();
		converted.setFloat(-INFINITY);
		converted.setDouble(-INFINITY);
	}
	else if (raw == "+inff" || raw == "inff")
	{
		converted.setCharImpossible();
		converted.setIntImpossible();
		converted.setFloat(INFINITY);
		converted.setDouble(INFINITY);
	}
	else if (raw == "nanf")
	{
		converted.setCharImpossible();
		converted.setIntImpossible();
		converted.setFloat(nanf(""));
		converted.setDouble(nan(""));
	}
	else
	{
		data = strtof(raw.c_str(), NULL);
		if (data > std::numeric_limits<int>::max() || data < std::numeric_limits<int>::min())
		{
			converted.setCharImpossible();
			converted.setIntImpossible();
		}
		else if (data > std::numeric_limits<char>::max() || data < std::numeric_limits<char>::min())
		{
			converted.setCharImpossible();
			converted.setInt(static_cast<int>(data));
		}
		else
		{
			converted.setChar(static_cast<char>(data));
			converted.setInt(static_cast<int>(data));
		}
		converted.setFloat(static_cast<float>(data));
		converted.setDouble(static_cast<double>(data));
	}
}

void
	fromDouble(Literal& converted, std::string raw)
{
	double	data;

	if (raw == "-inf")
	{
		converted.setCharImpossible();
		converted.setIntImpossible();
		converted.setFloat(-INFINITY);
		converted.setDouble(-INFINITY);
	}
	else if (raw == "+inf" || raw == "inf")
	{
		converted.setCharImpossible();
		converted.setIntImpossible();
		converted.setFloat(INFINITY);
		converted.setDouble(INFINITY);
	}
	else if (raw == "nan")
	{
		converted.setCharImpossible();
		converted.setIntImpossible();
		converted.setFloat(nanf(""));
		converted.setDouble(nan(""));
	}
	else
	{
		data = strtod(raw.c_str(), NULL);
		if (data > std::numeric_limits<float>::max() || data < -std::numeric_limits<float>::max())
		{
			converted.setCharImpossible();
			converted.setIntImpossible();
			converted.setFloatImpossible();
		}
		else if (data > std::numeric_limits<int>::max() || data < std::numeric_limits<int>::min())
		{
			converted.setCharImpossible();
			converted.setIntImpossible();
			converted.setFloat(static_cast<float>(data));
		}
		else if (data > std::numeric_limits<char>::max() || data < std::numeric_limits<char>::min())
		{
			converted.setCharImpossible();
			converted.setInt(static_cast<int>(data));
			converted.setFloat(static_cast<float>(data));
		}
		else
		{
			converted.setChar(static_cast<char>(data));
			converted.setInt(static_cast<int>(data));
			converted.setFloat(static_cast<float>(data));
		}
		converted.setDouble(data);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		if (argc < 2)
			std::cout << "Invalid usage: too few arguments" << std::endl;
		else
			std::cout << "Invalid usage: too many arguments" << std::endl;
		return (1);
	}

	Literal	converted;
	switch (getType(argv[1]))
	{
	case type_e(CHAR):
		fromChar(converted, argv[1]);
		break;
	case type_e(INT):
		fromInt(converted, argv[1]);
		break;
	case type_e(FLOAT):
		fromFloat(converted, argv[1]);
		break;
	case type_e(DOUBLE):
		fromDouble(converted, argv[1]);
		break;
	case type_e(OTHER):
		std::cout << "Invalid input: " << argv[1] << std::endl;
		return (1);
	}

	std::cout << converted;
}
