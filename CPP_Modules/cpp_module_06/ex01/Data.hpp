/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 18:09:24 by seyu              #+#    #+#             */
/*   Updated: 2021/04/12 18:11:44 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <string>

struct Data
{
	std::string	s1;
	int			n;
	std::string s2;
};

void*	serialize(void);
Data*	deserialize(void* raw);

#endif
