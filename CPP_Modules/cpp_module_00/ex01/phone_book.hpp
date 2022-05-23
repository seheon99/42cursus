/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 03:04:32 by seyu              #+#    #+#             */
/*   Updated: 2021/03/09 16:10:07 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include <string>
# include <iomanip>

# include "contact.hpp"

class phone_book
{
private:
	contact	contacts[8];
	int		num_of_contacts;
	void	print_list();
public:
	phone_book();
	~phone_book();

	int		add();
	int		search();
};

#endif
