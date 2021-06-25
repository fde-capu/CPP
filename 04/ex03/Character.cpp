/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:56:22 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/19 14:56:22 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <string>
#include <iostream>

Character::Character(std::string u_name)
: _name(u_name)
{
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = 0;
		equipped[i] = 0;
	}
	return ;
}

Character::Character(Character const & src)
{
	*this = src;
	return ;
}

AMateria * Character::getMateria(int i) const
{
	return _inventory[i];
}

Character & Character::operator = (Character const & rhs)
{
	if (this != &rhs)
	{
		_name = rhs.getName();
		for (int i = 0; i < 4; i++)
		{
			if (rhs.getMateria(i))
			{
				_inventory[i] = rhs.getMateria(i)->clone();
				equipped[i] = 1;
			}
			else
			{
				_inventory[i] = 0;
				equipped[i] = 0;
			}
		}
	}
	return *this;
}

std::string const & Character::getName() const
{
	return _name;
}

int Character::getSlotEquip() const
{
	int i = 0;
	while (i < 4)
	{
		if (!equipped[i])
			return i;
		i++;
	}
	return -1;
}

void Character::equip(AMateria* m)
{
	if (isEquipped(m) || m->isEquipped())
		return ;
	int i = getSlotEquip();
	if (i < 0)
		return ;
	m->equip();
	_inventory[i] = m;
	equipped[i] = 1;
	return ;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
		return ;
	delete _inventory[idx];
	_inventory[idx] = 0;
	equipped[idx] = 0;
	return ;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4 || !_inventory[idx])
		return ;
	_inventory[idx]->use(target);
	return ;
}

Character::~Character()
{
	delEquips();
	return ;
}

void Character::delEquips()
{
	for (int i = 0; i < 4; i++)
	{
		if (getMateria(i))
			delete _inventory[i];
		equipped[i] = 0;
	}
}

std::ostream & operator << (std::ostream & o, Character const & self)
{
	std::cout << "::Character:: " << self.getName() << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (self.getMateria(i))
			std::cout << "[" << i << "] " << *self.getMateria(i) << "\t" << self.getMateria(i) << std::endl;
	}
	return o;
}

int Character::isEquipped(const AMateria * m) const
{
	for (int i = 0; i < 4; i++)
	{
		if (!getMateria(i))
			continue ;
		if (m == getMateria(i) || m->getType() == getMateria(i)->getType())
			return 1;
	}
	return 0;
}
