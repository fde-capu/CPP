/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:55:49 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/19 14:55:49 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character
{
	private:
		std::string name;
		int			ap;
		AWeapon *	weapon;
	public:
		Character(std::string const & name);
		std::string getName(void) const;
		int getAP(void) const;
		AWeapon * getWeapon(void) const;
		~Character(void);
		void recoverAP();
		void equip(AWeapon*);
		void attack(Enemy*);
		Character(void);
		Character(Character const & src);
		Character &	operator = (Character const & rhs);
};

std::ostream &	operator << (std::ostream & o, Character const & i);

#endif

