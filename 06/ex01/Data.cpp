/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 11:34:47 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/17 09:06:21 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <iostream>

Data::Data(void)
{
	str_a = new std::string(random_string("StrA:", 5));
	r_int = random_int(-42, 42);
	str_b = new std::string(random_string("StrB:", 5));
	return ;
}

Data::~Data(void)
{
	delete str_a;
	delete str_b;
	return ;
}

Data::Data(Data const & src)
{
	*this = src;
}

Data & Data::operator= (const Data & rhs)
{
	if (this != &rhs)
	{
		str_a = new std::string(*rhs.str_a);
		r_int = rhs.r_int;
		str_b = new std::string(*rhs.str_b);
	}
	return *this;
}

bool Data::operator== (const Data & rhs)
{
	return	*str_a == *rhs.str_a
		&&	r_int == rhs.r_int
		&&	*str_b == *rhs.str_b;
}

std::ostream & operator<< (std::ostream & o, Data const & self)
{
	o << "::Data::";
	(void)self;
	return o;
}

