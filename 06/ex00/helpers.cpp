/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 08:42:50 by fde-capu          #+#    #+#             */
/*   Updated: 2021/06/10 16:04:03 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

int get_literal_type(std::string str)
{
	if (is_literal_int(str))
		return TYPE_INT;
	if (is_literal_char(str))
		return TYPE_CHAR;
	if (is_literal_float(str))
		return TYPE_FLOAT;
	if (is_literal_double(str))
		return TYPE_DOUBLE;
	return 0;
}

void plot_type(int t)
{
	if (t == TYPE_INT)
		std::cout << "Detected: int." << std::endl;
	if (t == TYPE_CHAR)
		std::cout << "Detected: char." << std::endl;
	if (t == TYPE_FLOAT)
		std::cout << "Detected: float." << std::endl;
	if (t == TYPE_DOUBLE)
		std::cout << "Detected: double." << std::endl;
	return ;
}
