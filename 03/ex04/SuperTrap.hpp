/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:54:32 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/19 14:54:32 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP
# include "NinjaTrap.hpp"
# include "FragTrap.hpp"
# include <iostream>

class SuperTrap : virtual public NinjaTrap, virtual public FragTrap
{
	private:
		static const int			_u_default[8];
		static const std::string	_u_pun[11];
		static const std::string	_u_obj_name;
		static const std::string	_u_robot_code;
	public:
		~SuperTrap(void);
		SuperTrap(std::string u_name);
};

#endif

