/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:55:48 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/19 14:55:48 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>
#include <string>
#include "AWeapon.hpp"
#include "Enemy.hpp"

Character::Character(std::string const & name)
: name(name), ap(40), weapon(0)
{
	return ;
}

Character::Character(void)
{
	return ;
}

Character::Character(Character const & src)
{
	*this = src;
	return ;
}

Character &	Character::operator = (Character const & rhs)
{
	if (this != &rhs)
	{
		name = rhs.getName();
		ap = rhs.getAP();
		weapon = rhs.getWeapon();
	}
	return *this;
}

std::ostream &	operator << (std::ostream & o, Character const & i)
{
	if (i.getWeapon())
	{
		o << i.getName() << " has " << i.getAP() << " AP and wields "
			<< i.getWeapon()->getName() << "." << std::endl;
	}
	else
	{
		o << i.getName() << " has " << i.getAP()
			<< " AP and is unarmed." << std::endl;
	}
	return o;
}

Character::~Character(void)
{
	return ;
}

void Character::recoverAP(void)
{
	ap = ap + 10 > 40 ? 40 : ap + 10;
	return ;
}

void Character::equip(AWeapon * w)
{
	weapon = w;
	return ;
}

void Character::attack(Enemy * e)
{
	if (!getWeapon())
		return ;
	int	weapon_cost = weapon->getAPCost();
	if (weapon_cost > ap)
		return ;
	ap -= weapon_cost;
	std::cout << name << " attacks " << e->getType() << " with a " << weapon->getName() << "." << std::endl;
	weapon->attack();
	e->takeDamage(weapon->getDamage());
	// Instead of making the enemy deletion here,
	// I find it more usefull to have a `this delete`
	// inside the Enemy when it dies (see Enemy.cpp).
	return ;
}

std::string Character::getName(void) const
{
	return name;
}

int Character::getAP(void) const
{
	return ap;
}

AWeapon * Character::getWeapon(void) const
{
	return weapon;
}
