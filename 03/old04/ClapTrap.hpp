/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:54:32 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/19 14:54:32 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>
# include <string>

class ClapTrap
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
		int				_default[8];
		std::string		_pun[11];
		std::string		_obj_name;
		std::string		_robot_code;
		void			setDefaults
						(	const int defaults[8],
							const std::string puns[11],
							std::string object_name,
							std::string robot_code		);
		ClapTrap(void);
		ClapTrap(ClapTrap const & src);
		ClapTrap &	operator = (ClapTrap const & rhs);
		~ClapTrap(void);
		std::string get_robot_code(void) const;
		std::string get_obj_name(void) const;
		std::string get_pun(const int i) const;
};

std::ostream &	operator << (std::ostream & o, ClapTrap const & i);

#endif
