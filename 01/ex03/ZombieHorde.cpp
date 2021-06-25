/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 07:23:51 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/27 15:02:33 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"
#include "ZombieHorde.hpp"
#include <iostream>

int ZombieHorde::_n = 0;

ZombieHorde::ZombieHorde(int N)
{
	_n = N <= 0 ? 0 : N;
	if (!_n)
		return ;
	std::cout << std::endl << "-- Horde of " << _n << " comming! --" << std::endl;
	z = new Zombie[_n];
	for (int i = 0; i < _n; i++)
		z[i].name = random_name();
	return ;
}

ZombieHorde::~ZombieHorde(void)
{
	delete [] z;
	return ;
}

void	ZombieHorde::announce(void)
{
	for (int i = 0; i < _n; i++)
		z[i].announce();
	return ;
}
