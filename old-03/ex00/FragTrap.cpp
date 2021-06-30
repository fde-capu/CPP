/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:59:59 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/19 14:59:59 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>
#include <cstdlib>

FragTrap::FragTrap(std::string u_name) :
	name(u_name),
	level(1),
	hit_points(100),
	max_hit_points(100),
	energy_points(100),
	max_energy_points(100),
	melee_attack_damage(30),
	ranged_attack_damage(20),
	armor_damage_reduction(5)
{
	std::srand((unsigned int)time(0));
	std::cout << "[sys]\t Default creation of rainbow fart." << std::endl;
	return ;
}

FragTrap::FragTrap(FragTrap const & src)
{
	std::cout << "[sys]\t Copy constructor through aura of death." << std::endl;
	*this = src;
	return ;
}

FragTrap &	FragTrap::operator = (FragTrap const & rhs)
{
	std::cout << "[sys]\t Assignment operator da-da-da electric." << std::endl;
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

std::ostream &	operator << (std::ostream & o, FragTrap const & i)
{
	o << std::endl;
	o << "| :: "					  << i.name << " ::" << std::endl;
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

void	FragTrap::rangedAttack(std::string const & target)
{
	if (hit_points < ranged_attack_damage)
	{
		std::cout << name << " does not have enough hit_points for ranged attack. Crap happens." << std::endl;
		return ;
	}
	hit_points -= ranged_attack_damage;
	std::cout << this->name << " attacks " << target << " at range, causing " << ranged_attack_damage << " points of damage! Yeehaw!" << std::endl;
	return ;
}

void	FragTrap::meleeAttack(std::string const & target)
{
	if (hit_points < melee_attack_damage)
	{
		std::cout << name << " does not have enough hit_points for melee attack. Poop." << std::endl;
		return ;
	}
	hit_points -= melee_attack_damage;
	std::cout << this->name << " melee attacks " << target << ", causing " << melee_attack_damage << " points of damage! Heyyah!" << std::endl;
	return ;
}

void	FragTrap::takeDamage(unsigned int amount)
{
	amount = amount > armor_damage_reduction ?
		amount - armor_damage_reduction : 0;
	if (!amount)
	{
		std::cout << this->name << " takes no damage! High five!" << std::endl;
		return ;
	}
	amount = amount < energy_points ? amount : energy_points;
	energy_points -= amount;
	std::cout << this->name << " defends " << armor_damage_reduction << " and takes " << amount << " points of damage! A popsicle robot." << std::endl;
	return ;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	unsigned int e_amount = amount + energy_points > max_energy_points ?
		max_hit_points - energy_points : amount;
	energy_points += e_amount;
	unsigned int hp_amount = amount + hit_points > max_hit_points ?
		max_hit_points - hit_points : amount;
	hit_points += hp_amount;
	std::cout << this->name << " repairs " << amount << "! Welcome to the jam." << std::endl;
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
	std::string rnd_attack = attacks[rand() % 6];
	std::cout << this->name << " [vaulhunter.exe]->(" << target << ") ...kukachow! Got some party started!" << std::endl;
	std::cout << " >> random attack: " << rnd_attack << " <<" << std::endl;
	return ;
}

FragTrap::~FragTrap(void)
{
	std::cout << "[sys]\t Destructor called with extra kapow." << std::endl;
	return ;
}
