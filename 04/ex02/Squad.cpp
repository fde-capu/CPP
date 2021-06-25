/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:56:12 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/19 14:56:12 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"
#include <iostream>

Squad::Squad(void)
: n_units(0), unit(0)
{
	return ;
}

Squad::Squad(Squad const & src)
{
	unit = 0;
	n_units = 0;
	for (int i = 0; i < src.getCount(); i++)
		push(src.getUnit(i)->clone());
	return ;
}

Squad & Squad::operator = (Squad const & rhs)
{
	if (this != &rhs)
	{
		if (n_units)
			del_units();
		for (int i = 0; i < rhs.getCount(); i++)
			push(rhs.getUnit(i)->clone());
	}
	return *this;
}

void Squad::del_units()
{
	for (int i = 0; i < n_units; i++)
		delete unit[i];
	delete [] unit;
	n_units = 0;
	return ;
}

Squad::~Squad(void)
{
	del_units();
	return ;
}

int Squad::getCount() const
{
	return n_units;
}

ISpaceMarine* Squad::getUnit(int x) const
{
	if (x < 0 || x >= n_units)
		return 0;
	return unit[x];
}

int Squad::push(ISpaceMarine * u_unit)
{
	if (!u_unit)
		return n_units;
	if (!n_units)
	{
		unit = new ISpaceMarine * [++n_units];
		unit[0] = u_unit;
		return (n_units);
	}
	for (int i = 0; i < n_units; i++)
		if (unit[i] == u_unit)
			return (n_units);
	ISpaceMarine ** x = new ISpaceMarine * [n_units + 1];
	for (int i = 0; i < n_units; i++)
		x[i] = unit[i];
	delete [] unit;
	x[n_units++] = u_unit;
	unit = x;
	return (n_units);
}
