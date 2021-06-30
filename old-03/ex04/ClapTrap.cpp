/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:54:32 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/19 14:54:32 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void)
{
//	int _default[8] = {};
	_obj_name = "obj[ClapTrap (parent)]";
	_robot_code = "CL4P-TP (p)";
	std::string _pun[11] = {"(p)","(p)","(p)","(p)","(p)","(p)","(p)","(p)","(p)","(p)","(p)"};
	std::cout << "[sys]\t " << _obj_name << ": Default (void) creation " << _pun[0] << "." << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
	std::cout << "[sys]\t " << src._obj_name << ": Copy constructor " << src.get_pun(1) << "." << std::endl;
	*this = src;
	return ;
}

ClapTrap &	ClapTrap::operator = (ClapTrap const & rhs)
{
	std::cout << "[sys]\t " << rhs._obj_name << ": Assignment operator, " << rhs.get_pun(2) << "." << std::endl;
	if (this != &rhs)
	{
		setDefaults(rhs._default, rhs._pun, rhs._obj_name, rhs._robot_code);
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

std::ostream &	operator << (std::ostream & o, ClapTrap const & i)
{
	o << std::endl;
	o << "| :: " << i.name << " :: (" << i._robot_code << ") ::" << std::endl;
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

ClapTrap::~ClapTrap(void)
{
	std::cout << "[sys:unique ClapTrap]\t " << _obj_name << ": Destructor called " << get_pun(10) << std::endl;
	return ;
}

std::string ClapTrap::get_robot_code(void) const
{
	return _robot_code;
}

std::string ClapTrap::get_obj_name(void) const
{
	return _obj_name;
}

std::string ClapTrap::get_pun(const int i) const
{
	return _pun[i];
}

void	ClapTrap::rangedAttack(std::string const & target)
{
	if (hit_points < ranged_attack_damage)
	{
		std::cout << name << " does not have enough hit_points for ranged attack. " << get_pun(3) << std::endl;
		return ;
	}
	hit_points -= ranged_attack_damage;
	std::cout << this->name << " attacks " << target << " at range, causing " << ranged_attack_damage << " points of damage! " << get_pun(4) << std::endl;
	return ;
}

void	ClapTrap::meleeAttack(std::string const & target)
{
	if (hit_points < melee_attack_damage)
	{
		std::cout << name << " does not have enough hit_points for melee attack. " << get_pun(5) << std::endl;
		return ;
	}
	hit_points -= melee_attack_damage;
	std::cout << this->name << " melee attacks " << target << ", causing " << melee_attack_damage << " points of damage! " << get_pun(6) << std::endl;
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	amount = amount > armor_damage_reduction ?
		amount - armor_damage_reduction : 0;
	if (!amount)
	{
		std::cout << this->name << " takes no damage! " << get_pun(7) << std::endl;
		return ;
	}
	amount = amount < energy_points ? amount : energy_points;
	energy_points -= amount;
	std::cout << this->name << " defends " << armor_damage_reduction << " and takes " << amount << " points of damage! " << get_pun(8) << std::endl;
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	unsigned int e_amount = amount + energy_points > max_energy_points ?
		max_hit_points - energy_points : amount;
	energy_points += e_amount;
	unsigned int hp_amount = amount + hit_points > max_hit_points ?
		max_hit_points - hit_points : amount;
	hit_points += hp_amount;
	std::cout << this->name << " repairs " << amount << "! " << get_pun(9) << std::endl;
	return ;
}

void	ClapTrap::setDefaults(const int d[8], const std::string p[11],
	std::string n, std::string r)
{
	for (int i = 0; i < 8; i++)
		_default[i] = d[i];
	for (int i = 0; i < 11; i++)
		_pun[i] = p[i];
	_obj_name = n;
	_robot_code = r;
	return ;
}
