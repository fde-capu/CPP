/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:53:59 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/19 14:53:59 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"
#include <iostream>
#include <cstdlib>

const int NinjaTrap::_u_default[8] = {1,60,60,120,120,60,5,0};
const std::string NinjaTrap::_u_pun[11] = {
		"of skilliciousness", "zippity doodah", "woah, Nelly",
		"You are ace high!",
		"Psychedelic, man!",
		"No, nononono, no!", "Glitching weirdness.", "You're the wub to my dub.",
		"- My robotic flesh! Aahh!",
		"Recompiling my combat code!",
		"- Hahaha... I ascend!"
	};
const std::string NinjaTrap::_u_obj_name = "obj[NinjaTrap]";
const std::string NinjaTrap::_u_robot_code = "N1NJ4-TP";

NinjaTrap::NinjaTrap(std::string u_name) : ClapTrap()
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

void	NinjaTrap::ninjaShoebox(NinjaTrap & target)
{
	std::cout << name << " attacks another NinjaTrap, named " << target.name << ". Look out below!" << std::endl;
	target.takeDamage(10);
	return ;
}

void	NinjaTrap::ninjaShoebox(ScavTrap & target)
{
	std::cout << name << " attacks the ScavTrap named " << target.name << ". Ha ha ha! Suck it!" << std::endl;
	target.takeDamage(10);
	return ;
}

void	NinjaTrap::ninjaShoebox(FragTrap & target)
{
	std::cout << name << " attacks the FragTrap named " << target.name << ". Oooh! Terrabits!" << std::endl;
	target.takeDamage(10);
	return ;
}

NinjaTrap::~NinjaTrap(void)
{
	std::cout << "[sys:unique NinjaTrap]\t " << _obj_name << ": Destructor called " << get_pun(10) << std::endl;
	return ;
}
