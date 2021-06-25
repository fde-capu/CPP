/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:56:22 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/19 14:56:22 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <string>
#include <iostream>

MateriaSource::MateriaSource(void)
: slot (0)
{
	for (int i = 0; i < 4; i++)
		known[i] = 0;
	return ;
}

MateriaSource::MateriaSource(MateriaSource const & src)
{
	*this = src;
	return ;
}

MateriaSource & MateriaSource::operator = (MateriaSource const & rhs)
{
	if (this != &rhs)
	{
		slot = 0;
		for (int i = 0; i < 4; i++)
			learnMateria(rhs.getKnown(i)->clone());
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* u)
{
	if (slot >= 4)
	{
		delete u;
		return ;
	}
	known[slot] = u;
	slot++;
	return ;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (known[i]->getType() == type)
			return known[i]->clone();
	}
	return 0;
}

AMateria * MateriaSource::getKnown(int i) const
{
	return known[i];
}

std::ostream & operator << (std::ostream & o, MateriaSource const & self)
{
	o << "::MateriaSource::" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (self.getKnown(i))
			o << "[" << i << "] " << *self.getKnown(i) << " \t" << self.getKnown(i) << std::endl;
	}
	return o;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		delete known[i];
}
