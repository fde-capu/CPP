/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MuddyWaters.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 09:51:29 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/15 10:48:43 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUDDYWATERS_HPP
# define MUDDYWATERS_HPP
# include "AMateria.hpp"

class MuddyWaters: public AMateria
{
	public:
		MuddyWaters(void);
		virtual MuddyWaters * clone () const;
		virtual void use(ICharacter& target);
};

#endif
