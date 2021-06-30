/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:53:38 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/19 14:53:38 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>
#include <cstdlib>

const int			FragTrap::_u_default[8] = {1,100,100,100,100,30,20,5};
const std::string	FragTrap::_u_pun[11] = {
		"of a rainbow fart", "through aura of death",
		"da-da-da electric", "Crap happens.", "Yeehaw!",
		"Poop.", "Heyyah!", "High five!",
		"A popsicle robot.",
		"Welcome to the jam.",
		"with extra kapow"
	};
const std::string FragTrap::_u_obj_name = "obj[FragTrap]";
const std::string FragTrap::_u_robot_code = "FR4G-TP";

FragTrap::FragTrap(std::string u_name) : ClapTrap()
{
	setDefaults(_u_default, _u_pun, _u_obj_name, _u_robot_code);
	name = u_name;
	level = _default[0];
	hit_points = _default[1];
	max_hit_points = _default[2];
	energy_points = _default[3];
	max_energy_points = _default[4];
	melee_attack_damage = _default[5];
	ranged_attack_damage = _default[6];
	armor_damage_reduction = _default[7];
	std::cout << "[sys]\t " << _obj_name << ": Default (named) creation " << get_pun(0) << "." << std::endl;
	return ;
}

void	FragTrap::vaulhunter_dot_exe(std::string const & target)
{
	if (energy_points < 25)
	{
		std::cout << name << " does not have enough energy_points for vaulhunter.exe. Oh well." << std::endl;
		return ;
	}
	energy_points -= 25;
	const std::string attacks[6] = {
		"Funzerker", "Meat Unicycle", "Shhhhh... trap",
		"Blightbot", "Mechromagician", "Miniontrap"
	};
	std::string rnd_attack = attacks[std::rand() % 6];
	std::cout << this->name << " [vaulhunter.exe]->(" << target << ") ...kukachow! Got some party started!" << std::endl;
	std::cout << " >> random attack: " << rnd_attack << " <<" << std::endl;
	return ;
}

FragTrap::~FragTrap(void)
{
	std::cout << "[sys:unique FragTrap]\t " << _obj_name << ": Destructor called " << get_pun(10) << std::endl;
	return ;
}
