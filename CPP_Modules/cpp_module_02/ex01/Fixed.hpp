/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 17:43:54 by seyu              #+#    #+#             */
/*   Updated: 2021/03/31 04:02:19 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <ostream>

class	Fixed
{
public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed& other);
	~Fixed();

	Fixed&	operator=(const Fixed& other);

	float	toFloat() const;
	int		toInt() const;

	int		getRawBits() const;
	void	setRawBits(int const raw);
private:
	static const int	_numFractBits = 8;
	int					_rawBits;
};

std::ostream&	operator<<(std::ostream& out, const Fixed& self);

#endif
