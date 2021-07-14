/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:55:02 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/14 09:19:46 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"
#include "Victim.hpp"
#include <iostream>
#include <string>

Sorcerer::Sorcerer(std::string u_name, std::string u_title) :
	name(u_name), title(u_title)
{
	std::cout << name << ", " << title << ", is born!" << std::endl;
	return ;
}

Sorcerer::Sorcerer(Sorcerer const & src)
{
	*this = src;
	return ;
}

Sorcerer & Sorcerer::operator= (Sorcerer const & rhs)
{
	if (this != &rhs)
	{
		this->name = rhs.name;
		this->title = rhs.title;
	}
	return *this;
}

std::ostream & operator<< (std::ostream & o, Sorcerer const & i)
{
	std::cout << "I am " << i.name << ", " << i.title << ", and I like ponies!" << std::endl;
	return o;
}

Sorcerer::~Sorcerer(void)
{
	std::cout << name << ", " << title << ", is dead. Consequences will never be the same!" << std::endl;
	return ;
}

void	Sorcerer::polymorph(Victim const & victim) const
{
	victim.getPolymorphed();
	return ;
}
