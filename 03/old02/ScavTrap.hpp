/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:53:43 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/19 14:53:43 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"
# include <iostream>

class ScavTrap : public ClapTrap
{
	private:
		static const int			_u_default[8];
		static const std::string	_u_pun[11];
		static const std::string	_u_obj_name;
		static const std::string	_u_robot_code;
	public:
		~ScavTrap(void);
		void						challengeNewcomer(std::string const & target);
		ScavTrap(std::string u_name);
};

#endif
