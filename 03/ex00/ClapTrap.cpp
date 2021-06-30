/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 10:38:14 by fde-capu          #+#    #+#             */
/*   Updated: 2021/06/30 11:35:27 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void)
: name("unnamed"), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "ClapTrap default constructor called (" << name << ")." << std::endl;
}

ClapTrap::ClapTrap(std::string u_name)
: name(u_name), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "ClapTrap named constructor called (" << name << ")." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
	std::cout << "ClapTrap copy constructor called (" << src.getName() << ")." << std::endl;
	*this = src;
}

ClapTrap &	ClapTrap::operator= (ClapTrap const & rhs)
{
	std::cout << "ClapTrap assignment operator called (" << rhs.getName() << ")." << std::endl;
	if (this != &rhs)
	{
		name = rhs.getName();
		hit_points = rhs.getHitPoints();
		energy_points = rhs.getEnergyPoints();
		attack_damage = rhs.getAttackDamage();
	}
	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called (" << name << ")." << std::endl;
}

void	ClapTrap::attack(std::string const & target)
{
	if (hit_points < attack_damage)
	{
		std::cout << name << " does not have enough hit_points for attack. " << std::endl;
		return ;
	}
	hit_points -= attack_damage;
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	amount = amount > energy_points ? energy_points : amount;
	amount = amount < 0 ? 0 : amount;
	if (!amount)
	{
		std::cout << name << " takes no damage! " << std::endl;
		return ;
	}
	energy_points -= amount;
	std::cout << "ClapTrap " << name << " takes " << amount << " points of damage! " << std::endl;
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	energy_points += amount;
	hit_points += amount;
	std::cout << "ClapTrap " << name << " repairs " << amount << "! " << std::endl;
	return ;
}

std::string ClapTrap::getName() const { return name; }
unsigned int ClapTrap::getHitPoints() const { return hit_points; }
unsigned int ClapTrap::getEnergyPoints() const { return energy_points; }
unsigned int ClapTrap::getAttackDamage() const { return attack_damage; }

std::ostream & operator<< (std::ostream & o, ClapTrap const & self)
{
	o << "::ClapTrap:: " << std::endl;
	o << " name: " << self.getName() << std::endl;
	o << " hit_points: " << self.getHitPoints() << std::endl;
	o << " energy_points: " << self.getEnergyPoints() << std::endl;
	o << " attack_damage: " << self.getAttackDamage() << std::endl;
	return o;
}
