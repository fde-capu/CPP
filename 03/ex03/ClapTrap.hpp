/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 10:38:17 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/01 12:16:08 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <string>
# include <iostream>

class ClapTrap
{
	private:
		static const std::string default_name;
		static const unsigned int ini_hit_points;
		static const unsigned int ini_energy_points;
		static const unsigned int ini_attack_damage;
		static const std::string class_name;
	protected:
		std::string		name;
		unsigned int	hit_points;
		unsigned int	energy_points;
		unsigned int	attack_damage;
	public:
		ClapTrap();
		ClapTrap(std::string u_name);
		ClapTrap(ClapTrap const & src);
		ClapTrap & operator= (ClapTrap const & rhs);
		~ClapTrap();
		void			attack(std::string const & target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		virtual std::string		getName() const;
		unsigned int	getHitPoints() const;
		unsigned int	getEnergyPoints() const;
		unsigned int	getAttackDamage() const;
};

std::ostream & operator<< (std::ostream & o, ClapTrap const & self);

#endif