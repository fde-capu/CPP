/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:54:32 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/19 14:54:32 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>
#include <cstdlib>

const int ScavTrap::_u_default[8] = {1,100,100,50,50,20,15,3};
const std::string ScavTrap::_u_pun[11] = {
		"of a badass", "freezy peezy", "boogie time",
		"I'm leaking!", "Ready for the punchline?",
		"NOOO!", "Shaken, not stirred.", "Make my day.",
		"Did you scratch the paint?",
		"Coffee? Black... like my soul.",
		"- Uh... wasn't me!"
	};
const std::string ScavTrap::_u_obj_name = "obj[ScavTrap]";
const std::string ScavTrap::_u_robot_code = "SC4V-TP";

ScavTrap::ScavTrap(std::string u_name) : ClapTrap()
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

void	ScavTrap::challengeNewcomer(std::string const & target)
{
	const std::string challenges[5] = {
		"You versus me! Me versus you! Either way!",
		"I will prove to you my robotic superiority!",
		"Dance batlle! Or, you know... regular battle.",
		"Man versus machine! Very tiny streamlined machine!",
		"Care to have a friendly duel?"
	};
	std::string rnd_challenge = challenges[std::rand() % 5];
	std::cout << this->name << " challenges " << target << ", a newcomer, with a random quote: " << std::endl;
	std::cout << " - " << rnd_challenge << std::endl;
	return ;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "[sys:unique ScavTrap]\t " << _obj_name << ": Destructor called " << get_pun(10) << std::endl;
	return ;
}
