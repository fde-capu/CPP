/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:56:22 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/19 14:56:22 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include "ICharacter.hpp"
# include <iostream>
# include <string>

class AMateria
{
	protected:
		std::string _type;
		unsigned int _xp;
		int equipped;
	public:
		AMateria(std::string const & type);
		virtual ~AMateria(void);
		std::string const & getType() const; //Returns the materia type
		unsigned int getXP() const; //Returns the Materia's XP
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
		AMateria(AMateria const & src);
		AMateria & operator = (AMateria const & rhs);
		void equip();
		int isEquipped() const;
};

std::ostream & operator << (std::ostream & o, AMateria const & self);

#endif
