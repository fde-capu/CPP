/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Debs.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 11:17:35 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/17 15:11:08 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Debs.hpp"
#include <string>
#include <iostream>

void deb(std::string x)
{
	if (!DEBUG)
		return ;
	std::cout << x << std::endl;
	return ;
}

void deb(int i, std::string x)
{
	if (!DEBUG)
		return ;
	std::cout << i << " " << x << std::endl;
	return ;
}
