/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:06:59 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/26 12:47:14 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB
# define HUMANB
# include "Weapon.hpp"

class	HumanB
{
	public:
		std::string	name;
		Weapon *	weapon;
		void		attack(void);
		void		setWeapon(Weapon &w);
					HumanB(std::string u_name);
};

#endif
