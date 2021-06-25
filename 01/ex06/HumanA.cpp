/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:10:08 by fde-capu          #+#    #+#             */
/*   Updated: 2021/06/02 12:50:13 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

/*
** Since HumanA constructor receives as weapon an stack object,
** we get it by reference. So HumanA::weapon is of type
** `Weapon &`: reference of Weapon (same address, same object).
*/

HumanA::HumanA(std::string u_name, Weapon & u_weapon)
: name(u_name), weapon(u_weapon)
{
	return ;
}

void	HumanA::attack(void)
{
	std::cout << this->name << " attacks with " << this->weapon.getType() << "." << std::endl;
	return ;
}
