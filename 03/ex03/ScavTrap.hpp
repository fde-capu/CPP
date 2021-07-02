/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:16:29 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/01 12:17:41 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"
# include <iostream>

class ScavTrap: virtual public ClapTrap
{
	protected:
		static const std::string default_name;
		static const unsigned int ini_hit_points;
		static const unsigned int ini_energy_points;
		static const unsigned int ini_attack_damage;
		static const std::string class_name;
		bool gate_keeper_mode; // Bonus (to save gate_keeper_mode).
	public:
		ScavTrap(); // Overloading eveything that needs a different output.
		ScavTrap(std::string); // This.
		~ScavTrap(); // This.
		void attack(std::string const & target); // And this.
		void guardGate();
		bool getGateKeeperMode() const;
		ScavTrap &	operator= (ScavTrap const & rhs);
};

std::ostream & operator<< (std::ostream & o, ScavTrap const & self);

#endif
