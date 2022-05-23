/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 17:43:54 by seyu              #+#    #+#             */
/*   Updated: 2021/03/30 17:22:54 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class	Fixed
{
public:
	Fixed();
	Fixed(const Fixed& other);
	~Fixed();

	Fixed&	operator=(const Fixed& other);
	int		getRawBits() const;
	void	setRawBits(int const raw);
private:
	static const int	_numFractBits = 8;
	unsigned int		_rawBits;
};


#endif
