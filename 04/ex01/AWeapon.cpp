/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:55:48 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/19 14:55:48 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"
#include <iostream>
#include <string>

AWeapon::AWeapon(std::string const & name, int apcost, int damage)
: name(name), apcost(apcost), damage(damage)
{
	return ;
}

AWeapon::AWeapon(AWeapon const & src)
{
	*this = src;
	return ;
}

AWeapon & AWeapon::operator = (AWeapon const & rhs)
{
	if (this != &rhs)
	{
		name = rhs.getName();
		damage = rhs.getDamage();
		apcost = rhs.getAPCost();
	}
	return *this;
}

std::ostream & operator << (std::ostream & o, AWeapon const & i)
{
	o << "::AWeapon::" << std::endl;
	o << "name: " << i.getName() << std::endl;
	o << "damage: " << i.getDamage() << std::endl;
	o << "ap cost: " << i.getAPCost() << std::endl;
	return o;
}

AWeapon::~AWeapon(void)
{
	return ;
}

std::string AWeapon::getName(void) const
{
	return name;
}

int AWeapon::getAPCost(void) const
{
	return apcost;
}

int AWeapon::getDamage(void) const
{
	return damage;
}
