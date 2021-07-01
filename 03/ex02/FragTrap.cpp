/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 08:40:15 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/01 08:46:50 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

const std::string FragTrap::default_name = "Generic FragTrap";
const unsigned int FragTrap::ini_hit_points = 100;
const unsigned int FragTrap::ini_energy_points = 100;
const unsigned int FragTrap::ini_attack_damage = 30;
const std::string FragTrap::class_name = "FragTrap";

FragTrap::FragTrap(void)
{
	name = default_name;
	hit_points = ini_hit_points;
	energy_points = ini_energy_points;
	attack_damage = ini_attack_damage;
	std::cout << class_name << " default constructor called (" << name << ")." << std::endl;
}

FragTrap::FragTrap(std::string u_name): ClapTrap(u_name)
{
	hit_points = ini_hit_points;
	energy_points = ini_energy_points;
	attack_damage = ini_attack_damage;
	std::cout << class_name << " named constructor called (" << name << ")." << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << class_name << " destructor called (" << name << ")." << std::endl;
}

void FragTrap::highFiveGuys(void)
{
	std::cout << class_name << " " << name << " gives a positive highfive!" << std::endl;
}
