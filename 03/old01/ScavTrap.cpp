/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:53:18 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/19 14:53:18 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>
#include <cstdlib>

ScavTrap::ScavTrap(std::string u_name) :
	name(u_name),
	level(1),
	hit_points(100),
	max_hit_points(100),
	energy_points(50),
	max_energy_points(50),
	melee_attack_damage(20),
	ranged_attack_damage(15),
	armor_damage_reduction(3)
{
	std::srand((unsigned int)time(0));
	std::cout << "[sys]\t Default creation of a badass." << std::endl;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const & src)
{
	std::cout << "[sys]\t Copy constructor freezy peezy!" << std::endl;
	*this = src;
	return ;
}

ScavTrap &	ScavTrap::operator = (ScavTrap const & rhs)
{
	std::cout << "[sys]\t Assignment operator, boogie time." << std::endl;
	if (this != &rhs)
	{
		name = rhs.name;
		level = rhs.level;
		hit_points = rhs.hit_points;
		max_hit_points = rhs.max_hit_points;
		energy_points = rhs.energy_points;
		max_energy_points = rhs.max_energy_points;
		melee_attack_damage = rhs.melee_attack_damage;
		ranged_attack_damage = rhs.ranged_attack_damage;
		armor_damage_reduction = rhs.armor_damage_reduction;
	}
	return *this;
}

std::ostream &	operator << (std::ostream & o, ScavTrap const & i)
{
	o << std::endl;
	o << "| :: "					  << i.name << " :: (SC4V-TP) ::" << std::endl;
	o << "|                  Level: " << i.level << std::endl;
	o << "|             Hit points: " << i.hit_points << std::endl;
	o << "|         Max hit points: " << i.max_hit_points << std::endl;
	o << "|          Energy points: " << i.energy_points << std::endl;
	o << "|      Max energy points: " << i.max_energy_points << std::endl;
	o << "|    Melee attack damage: " << i.melee_attack_damage << std::endl;
	o << "|   Ranged attack damage: " << i.ranged_attack_damage << std::endl;
	o << "| Armor damage reduction: " << i.armor_damage_reduction << std::endl;
	o << std::endl;
	return o;
}

void	ScavTrap::rangedAttack(std::string const & target)
{
	if (hit_points < ranged_attack_damage)
	{
		std::cout << name << " does not have enough hit_points for ranged attack. I'm leaking!" << std::endl;
		return ;
	}
	hit_points -= ranged_attack_damage;
	std::cout << this->name << " attacks " << target << " at range, causing " << ranged_attack_damage << " points of damage! Ready for the punchline?" << std::endl;
	return ;
}

void	ScavTrap::meleeAttack(std::string const & target)
{
	if (hit_points < melee_attack_damage)
	{
		std::cout << name << " does not have enough hit_points for melee attack. NOOO!" << std::endl;
		return ;
	}
	hit_points -= melee_attack_damage;
	std::cout << this->name << " melee attacks " << target << ", causing " << melee_attack_damage << " points of damage! Shaken, not stirred." << std::endl;
	return ;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	amount = amount > armor_damage_reduction ?
		amount - armor_damage_reduction : 0;
	if (!amount)
	{
		std::cout << this->name << " takes no damage! Make my day." << std::endl;
		return ;
	}
	amount = amount < energy_points ? amount : energy_points;
	energy_points -= amount;
	std::cout << this->name << " defends " << armor_damage_reduction << " and takes " << amount << " points of damage! Did you scratch the paint?" << std::endl;
	return ;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	unsigned int e_amount = amount + energy_points > max_energy_points ?
		max_hit_points - energy_points : amount;
	energy_points += e_amount;
	unsigned int hp_amount = amount + hit_points > max_hit_points ?
		max_hit_points - hit_points : amount;
	hit_points += hp_amount;
	std::cout << this->name << " repairs " << amount << "! Coffee? Black... like my soul." << std::endl;
	return ;
}

void	ScavTrap::challengeNewcomer(std::string const & target)
{
	const std::string challenges[5] = {
		"You versus me! Me versus you! Either way!",
		"I will prove to you my robotic superiority!",
		"Dance batlle! Or, you know... regular battle.",
		"Man verus machine! Very tiny streamlined machine!",
		"Care to have a friendly duel?"
	};
	std::string rnd_challenge = challenges[rand() % 5];
	std::cout << this->name << " challenges" << target << ", a new comer: " << std::endl;
	std::cout << " - " << rnd_challenge << std::endl;
	return ;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "[sys]\t Destructor called - Uh... wasn't me!" << std::endl;
	return ;
}
