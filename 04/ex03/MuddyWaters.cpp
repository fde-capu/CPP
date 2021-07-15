/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MuddyWaters.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 09:51:44 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/15 10:48:40 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MuddyWaters.hpp"

MuddyWaters::MuddyWaters()
: AMateria("muddy waters")
{ }

MuddyWaters * MuddyWaters::clone() const
{
	return new MuddyWaters();
}

void MuddyWaters::use(ICharacter & target)
{
	_xp += 13;
	std::cout << "* " << target.getName() << " is now a hoochie coochie *" << std::endl;
}
