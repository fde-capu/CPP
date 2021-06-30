/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:54:32 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/19 14:54:32 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"
# include <iostream>

# define	FR4G_TP_HIT_POINTS	100
# define	FR4G_TP_MAX_HIT_POINTS	100
# define	FR4G_TP_RANGED_ATTACK_DAMAGE	20
# define	FR4G_TP_ARMOR_DAMAGE_REDUCTION	5

class FragTrap : virtual public ClapTrap
{
	private:
		static const int			_u_default[8];
		static const std::string	_u_pun[11];
		static const std::string	_u_obj_name;
		static const std::string	_u_robot_code;
	public:
		void						vaulhunter_dot_exe(std::string const & target);
		~FragTrap(void);
		FragTrap(std::string u_name);
		void			rangedAttack(std::string const & target);
};

#endif
