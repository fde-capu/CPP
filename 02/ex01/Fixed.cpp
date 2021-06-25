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
#include <cmath>
#include <climits>

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

std::ostream &	operator << (std::ostream & o, Fixed const & fixed)
{
	o << fixed.toFloat();
	return o;
}

int	Fixed::getRawBits(void) const
{
	return _fixed_point_value;
}

void	Fixed::setRawBits(int const raw)
{
	_fixed_point_value = (int)raw;
	return ;
}

Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called." << std::endl;
	_fixed_point_value = i << _n_fractional_bits;
	return ;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called." << std::endl;
	_fixed_point_value = f * (1 << _n_fractional_bits);
	return ;
}

int	Fixed::toInt(void) const
{
	return _fixed_point_value >> _n_fractional_bits;
}

float	Fixed::toFloat(void) const
{
	return (float)_fixed_point_value / (float)(1 << _n_fractional_bits);
}
