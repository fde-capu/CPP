/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:53:59 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/19 14:53:59 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"
# include <iostream>

class FragTrap : public ClapTrap
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
};

#endif
