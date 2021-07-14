/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DealZap.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 15:03:27 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/14 16:59:57 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DealZap.hpp"
#include <iostream>

DealZap::DealZap()
: AWeapon("Deal Zap", 1, 1)
{}

void DealZap::attack() const
{
	std::cout << "* zzZap *" << std::endl;
}
