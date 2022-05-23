/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 21:43:21 by seyu              #+#    #+#             */
/*   Updated: 2021/04/12 22:16:48 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_HPP
# define B_HPP

# include "Base.hpp"

class	B : public Base
{
public:
	B();
	B(const B& other);
	virtual ~B();

	B&	operator=(const B& other);
private:
};

#endif
