/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:55:48 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/19 14:55:48 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"
#include <iostream>
#include <string>

Enemy::Enemy(int hp, std::string const & type)
: hp(hp), type(type)
{
	return ;
}

Enemy::Enemy(Enemy const & src)
{
	*this = src;
	return ;
}

Enemy & Enemy::operator = (Enemy const & rhs)
{
	if (this != &rhs)
	{
		hp = rhs.getHP();
		type = rhs.getType();
	}
	return *this;
}

std::ostream & operator << (std::ostream & o, Enemy const & i)
{
	o << "::Enemy::" << std::endl;
	o << "hp: " << i.getHP() << std::endl;
	o << "type: " << i.getType() << std::endl;
	return o;
}

Enemy::~Enemy(void)
{
	return ;
}

std::string Enemy::getType(void) const
{
	return type;
}

int Enemy::getHP(void) const
{
	return hp;
}

void Enemy::takeDamage(int d)
{
	if (d <= 0)
		return ;
	hp = hp - d <= 0 ? 0 : hp - d;
	if (hp == 0)
		delete this;
	return ;
}
