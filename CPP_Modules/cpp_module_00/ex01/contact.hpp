/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 03:10:38 by seyu              #+#    #+#             */
/*   Updated: 2021/03/09 13:33:17 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class	contact
{
private:
	static std::string	_field_names[11];
	std::string 		_infos[11];
public:
	contact();
	~contact();
	int			store_infos();
	void		print_infos();
	std::string	get_info(int index);
};

enum	field_name_e
{
	F_FIRST_NAME = 0,
	F_LAST_NAME,
	F_NICKNAME,
	F_LOGIN,
	F_POSTAL,
	F_EMAIL,
	F_PHONE,
	F_BIRTH,
	F_FAV_MEAL,
	F_UND_COLOR,
	F_SECRET
};

#endif
