/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlanctonHoney.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 09:39:26 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/15 10:48:32 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANCTONHONEY_HPP
# define PLANCTONHONEY_HPP
# include "AMateria.hpp"

class PlanctonHoney: public AMateria
{
	public:
		PlanctonHoney(void);
		virtual PlanctonHoney * clone () const;
		virtual void use(ICharacter& target);
};

#endif
