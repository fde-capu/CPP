/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:20:17 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/01 08:35:58 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

const std::string ScavTrap::default_name = "Generic ScavTrap";
const unsigned int ScavTrap::ini_hit_points = 100;
const unsigned int ScavTrap::ini_energy_points = 50;
const unsigned int ScavTrap::ini_attack_damage = 20;
const std::string ScavTrap::class_name = "ScavTrap";
bool ScavTrap::getGateKeeperMode() const { return gate_keeper_mode; }

ScavTrap::ScavTrap(void)
{
	name = default_name;
	hit_points = ini_hit_points;
	energy_points = ini_energy_points;
	attack_damage = ini_attack_damage;
	gate_keeper_mode = 0;
	std::cout << class_name << " default constructor called (" << name << ")." << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string u_name) : ClapTrap(u_name)
{
	hit_points = ini_hit_points;
	energy_points = ini_energy_points;
	attack_damage = ini_attack_damage;
	gate_keeper_mode = 0;
	std::cout << class_name << " named constructor called (" << name << ")." << std::endl;
}

ScavTrap &	ScavTrap::operator= (ScavTrap const & rhs)
{
	std::cout << class_name << " " << name << " assignment operator called." << std::endl;
	if (this != &rhs)
	{
		gate_keeper_mode = rhs.getGateKeeperMode();
	}
	return *this;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << class_name << " destructor called (" << name << ")." << std::endl;
	return ;
}

void	ScavTrap::attack(std::string const & target)
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
void	ScavTrap::guardGate()
{
	gate_keeper_mode = 1;
	std::cout << class_name << " " << name << " entered gate keeper mode." << std::endl;
}

std::ostream & operator<< (std::ostream & o, ScavTrap const & self)
{
	std::cout << static_cast<ClapTrap>(self);
	std::cout << " gate_keeper_mode: " << self.getGateKeeperMode() << std::endl;
	return o;
}
