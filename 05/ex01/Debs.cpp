/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Debs.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:56:53 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/19 14:56:53 by fde-capu         ###   ########.fr       */
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
