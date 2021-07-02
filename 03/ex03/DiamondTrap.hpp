/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 10:10:03 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/01 12:23:09 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include <iostream>

class DiamondTrap: virtual public FragTrap, virtual public ScavTrap
{
	private:
		std::string name;
		static const std::string default_name;
		static const unsigned int ini_hit_points;
		static const unsigned int ini_energy_points;
		static const unsigned int ini_attack_damage;
		static const std::string class_name;
	public:
		DiamondTrap(void);
		DiamondTrap(std::string);
		DiamondTrap(DiamondTrap const & src);
		~DiamondTrap(void);
		std::string		getName() const;
		void whoAmI();
		// attack() is already pointing to ScavTrap since virtual inheritance.
};

std::ostream & operator<< (std::ostream & o, DiamondTrap const & self);

#endif
