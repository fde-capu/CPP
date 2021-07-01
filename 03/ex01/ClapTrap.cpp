/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 10:38:14 by fde-capu          #+#    #+#             */
/*   Updated: 2021/06/30 16:56:56 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

const std::string  ClapTrap::default_name = "Generic ClapTrap";
const unsigned int ClapTrap::ini_hit_points = 10;
const unsigned int ClapTrap::ini_energy_points = 10;
const unsigned int ClapTrap::ini_attack_damage = 0;
const std::string  ClapTrap::class_name = "ClapTrap";

ClapTrap::ClapTrap(void)
{
	name = default_name;
	hit_points = ini_hit_points;
	energy_points = ini_energy_points;
	attack_damage = ini_attack_damage;
	std::cout << class_name << " default constructor called (" << name << ")." << std::endl;
}

ClapTrap::ClapTrap(std::string u_name)
{
	name = u_name;
	hit_points = ini_hit_points;
	energy_points = ini_energy_points;
	attack_damage = ini_attack_damage;
	std::cout << class_name << " named constructor called (" << name << ")." << std::endl;
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
	std::cout << class_name << " destructor called (" << name << ")." << std::endl;
}

void	ClapTrap::attack(std::string const & target)
{
	if (hit_points < attack_damage)
	{
		std::cout << name << " does not have enough hit_points for attack." << std::endl;
		return ;
	}
	hit_points -= attack_damage;
	std::cout << class_name << " " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
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
	o << " name: " << self.getName() << std::endl;
	o << " hit_points: " << self.getHitPoints() << std::endl;
	o << " energy_points: " << self.getEnergyPoints() << std::endl;
	o << " attack_damage: " << self.getAttackDamage() << std::endl;
	return o;
}
