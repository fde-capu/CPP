/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:54:32 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/19 14:54:32 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"
#include "NinjaTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>
#include <cstdlib>

const int			SuperTrap::_u_default[8] = {1,
	FR4G_TP_HIT_POINTS,FR4G_TP_MAX_HIT_POINTS,
	N1NJ4_TP_ENERGY_POINTS,N1NJ4_TP_MAX_ENERGY_POINTS,
	N1NJ4_TP_MELLE_ATTACK_DAMAGE,
	FR4G_TP_RANGED_ATTACK_DAMAGE,
	FR4G_TP_ARMOR_DAMAGE_REDUCTION};
const std::string	SuperTrap::_u_pun[11] = {
		"of a mean acid machine", "through the thinking of cheese",
		"dubstep dubstep", "I feel like an idiot now.", "Oooh, shiny!",
		"You got me.", "Look at me! I'm dancing!", "Ooh, yeah! Watch me!",
		"Good, I didn't want any spare parts.",
		"Who's a badass robot?",
		"with yo momma joke"
	};
const std::string SuperTrap::_u_obj_name = "obj[SuperTrap]";
const std::string SuperTrap::_u_robot_code = "SUP3R-TP";

SuperTrap::SuperTrap(std::string u_name) : NinjaTrap("ninjaNoName"), FragTrap("fragNoName")
{
	std::srand((unsigned int)time(0));
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

SuperTrap::~SuperTrap(void)
{
	std::cout << "[sys:unique SuperTrap]\t " << _obj_name << ": Destructor called " << get_pun(10) << std::endl;
	return ;
}

