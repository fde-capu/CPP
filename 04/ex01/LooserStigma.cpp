/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LooserStigma.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 15:11:44 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/14 17:03:55 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LooserStigma.hpp"
#include <iostream>

LooserStigma::LooserStigma()
: AWeapon("Looser Stigma", 11, 10)
{}

void LooserStigma::attack() const
{
	std::cout << "Looserrr!" << std::endl;
}
