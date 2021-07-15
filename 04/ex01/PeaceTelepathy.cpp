/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PeaceTelepathy.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 14:52:40 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/14 16:59:54 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PeaceTelepathy.hpp"
#include <iostream>

PeaceTelepathy::PeaceTelepathy()
: AWeapon("Peace Telepathy", 40, 0)
{}

void PeaceTelepathy::attack() const
{
	std::cout << "* ...ooOoOooOhmMmmMmm... *" << std::endl;
}
