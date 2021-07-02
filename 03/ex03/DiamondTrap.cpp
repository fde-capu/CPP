/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 10:19:43 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/01 13:35:50 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

const std::string  DiamondTrap::default_name = "Generic DiamondTrap";
const unsigned int DiamondTrap::ini_hit_points = FragTrap::ini_hit_points;
const unsigned int DiamondTrap::ini_energy_points = ScavTrap::ini_energy_points;
const unsigned int DiamondTrap::ini_attack_damage = FragTrap::ini_attack_damage;
const std::string  DiamondTrap::class_name = "DiamondTrap";

DiamondTrap::DiamondTrap(void)
{
	ClapTrap::name = default_name + "_clap_name";
	DiamondTrap::name = default_name;
	hit_points = ini_hit_points;
	energy_points = ini_energy_points;
	attack_damage = ini_attack_damage;
	gate_keeper_mode = 0;
	std::cout << class_name << " default constructor called (" << name << ")." << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(std::string u_name)
{
	ClapTrap::name = u_name + "_clap_name";
	DiamondTrap::name = u_name;
	hit_points = ini_hit_points;
	energy_points = ini_energy_points;
	attack_damage = ini_attack_damage;
	gate_keeper_mode = 0;
	std::cout << class_name << " named constructor called (" << name << ")." << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const & src)
{
	*this = src;
	return ;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << class_name << " destructor called (" << name << ")." << std::endl;
	return ;
}

std::ostream & operator<< (std::ostream & o, DiamondTrap const & self)
{
	std::cout << static_cast<ClapTrap>(self);
	std::cout << " gate_keeper_mode: " << self.getGateKeeperMode() << std::endl;
	return o;
}

std::string DiamondTrap::getName() const { return DiamondTrap::name; }

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondClap name: " << DiamondTrap::name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::name << std::endl;
}
