/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 04:55:34 by seyu              #+#    #+#             */
/*   Updated: 2021/03/25 17:17:55 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

# include "Brain.hpp"

class	Human
{
private:
	const Brain		_brain;
public:
	const Brain&	getBrain() const;
	const Brain*	identify() const;
};

#endif
