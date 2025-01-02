/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:30:24 by fde-capu          #+#    #+#             */
/*   Updated: 2022/01/28 17:51:57 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>
#include <sstream>
#include <cmath>

std::string random_string(std::string fixed, int len)
{
	std::stringstream out;
	out << fixed;
	for (int i = 0; i < len; i++)
		out << static_cast<unsigned char>((rand() % ('~' - ' ')) + ' ');
	return out.str();
}

Brain::Brain(void)
{
	for (int i = 0; i < brain_size; i++)
		ideas[i] = random_string("", idea_size);
	return ;
}

Brain::Brain(Brain const & src)
{
	*this = src;
	return ;
}

Brain & Brain::operator= (Brain const & rhs)
{
	std::cout << "!!!";
	if (this != &rhs)
	{
		std::cout << "!!!";
		for (int i = 0; i < brain_size; i++)
			ideas[i] = rhs.ideas[i];
	}
	return *this;
}

Brain::~Brain(void)
{
	return ;
}

void Brain::show_brain()
{
	std::cout << this << " >> ";
	for (int i = 0; i < idea_size; i++)
		std::cout << "[ " << ideas[i] << " ] ";
	std::cout << std::endl;
}
