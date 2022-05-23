/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 21:42:38 by seyu              #+#    #+#             */
/*   Updated: 2021/04/12 22:16:42 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_HPP
# define A_HPP

# include "Base.hpp"

class	A : public Base
{
public:
	A();
	A(const A& other);
	virtual ~A();

	A&	operator=(const A& other);
private:
};

#endif
