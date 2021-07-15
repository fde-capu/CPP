/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:56:22 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/15 07:57:50 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include "IMateriaSource.hpp"
# include <string>
# include <iostream>

class MateriaSource: public IMateriaSource
{
	private:
		AMateria * known[4];
		int slot;
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const & src);
		MateriaSource & operator= (MateriaSource const & rhs);
		virtual ~MateriaSource();
		virtual void learnMateria(AMateria*);
		virtual AMateria* createMateria(std::string const & type);
		AMateria * getKnown(int i) const;
};

std::ostream & operator<< (std::ostream & o, MateriaSource const & self);

#endif
