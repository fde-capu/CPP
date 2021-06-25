/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 13:59:08 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/26 12:24:29 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string u_type)
{
	type = u_type.length() ? u_type : "bare hands";
}

void Weapon::setType(std::string u_type)
{
	this->type.assign(u_type);
	return ;
}

std::string 	Weapon::getType(void)
{
	return this->type;
}
