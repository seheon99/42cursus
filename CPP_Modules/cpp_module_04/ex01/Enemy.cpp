/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 04:50:24 by seyu              #+#    #+#             */
/*   Updated: 2021/04/08 01:38:19 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy()
		: _hp(0), _type(std::string())
{}

Enemy::Enemy(int hp, std::string const& type)
		: _hp(hp), _type(type)
{}

Enemy::Enemy(Enemy const& other)
{
	*this = other;
}

Enemy::~Enemy()
{}

Enemy&
	Enemy::operator=(Enemy const& other)
{
	_hp = other._hp;
	_type = other._type;
	return (*this);
}

void
	Enemy::takeDamage(int damage)
{
	if (damage < 0)
		return ;
	_hp -= damage;
	if (_hp < 0)
		_hp = 0;
}

std::string const
	Enemy::getType() const
{
	return (_type);
}

int	Enemy::getHP() const
{
	return (_hp);
}
