/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlanctonHoney.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 09:39:36 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/15 10:51:32 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlanctonHoney.hpp"
#include <iostream>

PlanctonHoney::PlanctonHoney()
: AMateria("plancton honey")
{ }

PlanctonHoney * PlanctonHoney::clone() const
{
	return new PlanctonHoney();
}

void PlanctonHoney::use(ICharacter & target)
{
	_xp += 12;
	std::cout << "* gives sparkling sweet potion to " << target.getName() << " *" << std::endl;
}
