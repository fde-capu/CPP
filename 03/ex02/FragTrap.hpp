/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 08:38:36 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/01 08:45:02 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"
# include <string>

class FragTrap: public ClapTrap
{
	private:
		static const std::string default_name;
		static const unsigned int ini_hit_points;
		static const unsigned int ini_energy_points;
		static const unsigned int ini_attack_damage;
		static const std::string class_name;
	public:
		FragTrap();
		FragTrap(std::string);
		~FragTrap();
		void highFiveGuys(void);
};

#endif
