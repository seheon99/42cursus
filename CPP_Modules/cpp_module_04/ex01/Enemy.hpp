/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 04:45:50 by seyu              #+#    #+#             */
/*   Updated: 2021/04/08 01:41:11 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <string>

class	Enemy
{
public:
	Enemy(int hp, std::string const& type);
	Enemy(Enemy const& other);
	virtual ~Enemy();

	Enemy&				operator=(Enemy const& other);

	std::string const	getType() const;
	int					getHP() const;
	virtual void		takeDamage(int damage);
protected:
	Enemy();
private:
	int				_hp;
	std::string		_type;
};

#endif
