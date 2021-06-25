/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:55:02 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/19 14:55:02 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"
#include <iostream>
#include <string>

Victim::Victim(void)
{
	return ;
}

Victim::Victim(std::string u_name) : name(u_name)
{
	std::cout << "Some random victim called " << name << " just appeared!" << std::endl;
	return ;
}

Victim::Victim(Victim const & src)
{
	*this = src;
	return ;
}

Victim &	Victim::operator = (Victim const & rhs)
{
	if (this != &rhs)
	{
		this->name = rhs.name;
	}
	return *this;
}

std::ostream &	operator << (std::ostream & o, Victim const & i)
{
	o << "I'm " << i.name << " and I like otters!" << std::endl;
	return o;
}

Victim::~Victim(void)
{
	std::cout << "Victim " << name << " just died for no apparent reason!" << std::endl;
	return ;
}

void Victim::getPolymorphed(void) const
{
	std::cout << name << " has been turned into a cute little sheep!" << std::endl;
}
