/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:54:32 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/19 14:54:32 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>
#include <cstdlib>

const int NinjaTrap::_u_default[8] = {1,60,60,N1NJ4_TP_ENERGY_POINTS,
	N1NJ4_TP_MAX_ENERGY_POINTS,N1NJ4_TP_MELLE_ATTACK_DAMAGE,5,0};
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

void	NinjaTrap::meleeAttack(std::string const & target)
{
	std::cout << "[sys]\tLocal call of NinjaTrap::meleeAttack." << std::endl;
	if (hit_points < melee_attack_damage)
	{
		std::cout << name << " does not have enough hit_points for melee attack. " << get_pun(5) << std::endl;
		return ;
	}
	hit_points -= melee_attack_damage;
	std::cout << this->name << " melee attacks " << target << ", causing " << melee_attack_damage << " points of damage! " << get_pun(6) << std::endl;
	return ;
}

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
	std::cout << name << " attacks the NinjaTrap " << target.name << std::endl;
	target.takeDamage(10);
	return ;
}

void	NinjaTrap::ninjaShoebox(ScavTrap & target)
{
	std::cout << name << " attacks the ScavTrap " << target.name << std::endl;
	target.takeDamage(10);
	return ;
}

void	NinjaTrap::ninjaShoebox(FragTrap & target)
{
	std::cout << name << " attacks the FragTrap " << target.name << std::endl;
	target.takeDamage(10);
	return ;
}

NinjaTrap::~NinjaTrap(void)
{
	std::cout << "[sys:unique NinjaTrap]\t " << _obj_name << ": Destructor called " << get_pun(10) << std::endl;
	return ;
}
