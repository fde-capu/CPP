/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:59:59 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/19 14:59:59 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void) : _fixed_point_value(0)
{
	std::cout << "Default constructor called." << std::endl;
	return ;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called." << std::endl;
	*this = src;
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called." << std::endl;
	return ;
}

Fixed &	Fixed::operator = (Fixed const & rhs)
{
	std::cout << "Assignation operator called." << std::endl;
	if (this != &rhs)
	{
		this->_fixed_point_value = rhs.getRawBits();
	}
	return *this;
}

std::ostream &	operator << (std::ostream & o, Fixed const & i)
{
	o << "::Fixed::" << std::endl;
	(void)i;
	return o;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called." << std::endl;
	return _fixed_point_value;
}

void	Fixed::setRawBits(int const raw)
{
	_fixed_point_value = (int)raw;
	return ;
}
