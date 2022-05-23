/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 15:24:03 by seyu              #+#    #+#             */
/*   Updated: 2021/03/25 16:29:08 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP

# include <string>

class Pony
{
private:
	int			height;
	int			weight;
	int			age;
	std::string	name;
public:
	Pony();
	Pony(std::string pony_name);
	~Pony();

	int	print_infos(void);
};

#endif
