/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:53:19 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/19 14:53:19 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>

class ScavTrap
{
	public:
		std::string		name;
		unsigned int	level;
		unsigned int	hit_points;
		unsigned int	max_hit_points;
		unsigned int	energy_points;
		unsigned int	max_energy_points;
		unsigned int	melee_attack_damage;
		unsigned int	ranged_attack_damage;
		unsigned int	armor_damage_reduction;
		void			rangedAttack(std::string const & target);
		void			meleeAttack(std::string const & target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		void			challengeNewcomer(std::string const & target);
		ScavTrap(std::string u_name);
		ScavTrap(ScavTrap const & src);
		ScavTrap &	operator = (ScavTrap const & rhs);
		~ScavTrap(void);
};

std::ostream &	operator << (std::ostream & o, ScavTrap const & i);

#endif

