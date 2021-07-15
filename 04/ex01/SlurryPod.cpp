/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SlurryPod.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 15:40:18 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/14 16:30:33 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SlurryPod.hpp"
#include <iostream>

SlurryPod::SlurryPod(void)
: Enemy(242, "Slurry Pod")
{
	std::cout << "* bzzoinn bzzoim bzzoim *" << std::endl;
	return ;
}

SlurryPod::~SlurryPod(void)
{
	std::cout << "* CRASHKABOOM *" << std::endl;
	return ;
}
