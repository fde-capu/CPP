/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:55:49 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/14 16:41:01 by fde-capu         ###   ########.fr       */
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
	private:
		Character();
	public:
		virtual ~Character();
		Character(Character const & src);
		Character &	operator= (Character const & rhs);
		Character(std::string const & name);
		std::string getName() const;
		int getAP() const;
		AWeapon * getWeapon() const;
		void recoverAP();
		void equip(AWeapon*);
		void attack(Enemy*);
};

std::ostream & operator<< (std::ostream & o, Character const & i);

#endif

