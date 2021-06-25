/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:10:36 by fde-capu          #+#    #+#             */
/*   Updated: 2021/06/02 12:52:11 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

/*
** HumanB has their weapon set after the constructor
** with no default initializer. Once created, their weapon
** is NULL. Hence:
** - HumanB::weapon is a pointer (`Weapon *`), so it will only
** later point to a Weapon object.
** - HumanB::setWeapon takes a reference for an &Weapon and
** plugs it to the object.
*/

HumanB::HumanB		(std::string u_name) : name(u_name)
{
	this->weapon = 0;
	return ;
}

void	HumanB::setWeapon	(Weapon &w)
{
	weapon = &w;
	return ;
}

void	HumanB::attack	(void)
{
	std::cout << this->name << " attacks with " << this->weapon->getType() << "." << std::endl;
	return ;
}
