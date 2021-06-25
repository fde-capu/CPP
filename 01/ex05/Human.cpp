/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 13:00:55 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/23 13:51:50 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human(void) : brain(Brain(0.4))
{
	return ;
}

std::string	Human::identify(void)
{
	return brain.identify();
}

const Brain	&	Human::getBrain(void)
{
	return brain;
}
