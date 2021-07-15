/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:56:22 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/15 12:06:22 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <string>
#include <iostream>

AMateria::AMateria(std::string const & type)
: _type(type), _xp(0), equipped(0)
{
	return ;
}

AMateria::AMateria(AMateria const & src)
{
	*this = src;
	return ;
}

AMateria & AMateria::operator= (AMateria const & rhs)
{
	if (this != &rhs)
	{
		_type = rhs.getType();
		_xp = rhs.getXP();
	}
	return *this;
}

AMateria::~AMateria(void)
{
	return ;
}

std::string const & AMateria::getType() const
{
	return _type;
}

unsigned int AMateria::getXP() const
{
	return _xp;
}

std::ostream & operator << (std::ostream & o, AMateria const & self)
{
	o << "AMateria:: " << self.getType() << "\tXP:" << self.getXP();
	return o;
}

void AMateria::equip()
{
	equipped = 1;
	return ;
}

int AMateria::isEquipped() const
{
	return equipped;
}

void AMateria::unequip()
{
	equipped = 0;
	return ;
}
