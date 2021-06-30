/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:54:32 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/19 14:54:32 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include <iostream>

# define	N1NJ4_TP_ENERGY_POINTS	120
# define	N1NJ4_TP_MAX_ENERGY_POINTS	120
# define	N1NJ4_TP_MELLE_ATTACK_DAMAGE	60

class NinjaTrap : virtual public ClapTrap
{
	private:
		static const int			_u_default[8];
		static const std::string	_u_pun[11];
		static const std::string	_u_obj_name;
		static const std::string	_u_robot_code;
	public:
		~NinjaTrap(void);
		void						ninjaShoebox(NinjaTrap & target);
		void						ninjaShoebox(ScavTrap & target);
		void						ninjaShoebox(FragTrap & target);
		NinjaTrap(std::string u_name);
		void			meleeAttack(std::string const & target);
};

#endif
