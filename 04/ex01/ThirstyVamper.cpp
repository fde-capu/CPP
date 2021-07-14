/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ThirstyVamper.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 15:40:21 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/14 15:46:39 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ThirstyVamper.hpp"
#include <iostream>

ThirstyVamper::ThirstyVamper(void)
: Enemy(117, "Thirsty Vamper")
{
	std::cout << "* Nhshlp... *" << std::endl;
	return ;
}

ThirstyVamper::~ThirstyVamper(void)
{
	std::cout << "* PLAFF *" << std::endl;
	return ;
}
