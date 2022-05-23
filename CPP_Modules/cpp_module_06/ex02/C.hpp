/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 21:43:47 by seyu              #+#    #+#             */
/*   Updated: 2021/04/12 22:16:52 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_HPP
# define C_HPP

# include "Base.hpp"

class	C : public Base
{
public:
	C();
	C(const C& other);
	virtual ~C();

	C&	operator=(const C& other);
private:
};

#endif
