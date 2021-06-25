/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:56:22 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/19 14:56:22 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"
# include "AMateria.hpp"
# include <string>
# include <iostream>

class Character: public ICharacter
{
	private:
		std::string _name;
		AMateria * _inventory[4];
		int equipped[4];
		void delEquips();
		int isEquipped(const AMateria * m) const;
		int getSlotEquip() const;
	public:
		virtual ~Character();
		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
		Character(std::string u_name);
		Character(Character const & src);
		Character & operator = (Character const & rhs);
		AMateria * getMateria(int) const;
};

std::ostream & operator << (std::ostream & o, Character const & self);

#endif
