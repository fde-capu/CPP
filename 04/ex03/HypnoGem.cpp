/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HypnoGem.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 09:46:45 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/15 15:27:48 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HypnoGem.hpp"

HypnoGem::HypnoGem()
: AMateria("gem of hypnosis")
{ }

HypnoGem * HypnoGem::clone() const
{
	return new HypnoGem();
}

void HypnoGem::use(ICharacter & target)
{
	_xp += 14;
	std::cout << "* ..." << target.getName() << " is getting sleepy... *" << std::endl;
}
