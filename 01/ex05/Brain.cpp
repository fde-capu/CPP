/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 13:00:52 by fde-capu          #+#    #+#             */
/*   Updated: 2021/06/02 12:47:40 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>
#include <sstream>

Brain::Brain(float bv) : blood_volume(bv)
{
//	std::cout << identify() << " << Brain created." << std::endl;
	// The above line is usefull to inspect the Brain creation.
	// As it is not required to announce the creation, it is commented.
	return ;
}

std::string Brain::identify(void) const
{
	std::ostringstream	blood_stream;
	blood_stream << this;
	return blood_stream.str();
}
