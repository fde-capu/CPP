/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:59:59 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/19 14:59:59 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>

class FragTrap
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
		void			vaulhunter_dot_exe(std::string const & target);
		FragTrap(std::string u_name);
		FragTrap(FragTrap const & src);
		FragTrap &	operator = (FragTrap const & rhs);
		~FragTrap(void);
};

std::ostream &	operator << (std::ostream & o, FragTrap const & i);

#endif

