/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:59:59 by fde-capu          #+#    #+#             */
/*   Updated: 2021/06/24 08:44:40 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <climits>

bool Fixed::log_messages = 1;

Fixed::Fixed(void) : _fixed_point_value(0)
{
	if (log_messages)
		std::cout << "Default constructor called." << std::endl;
	return ;
}

Fixed::Fixed(Fixed const & src)
{
	if (log_messages)
		std::cout << "Copy constructor called." << std::endl;
	*this = src;
	return ;
}

Fixed::~Fixed(void)
{
	if (log_messages)
		std::cout << "Destructor called." << std::endl;
	return ;
}

Fixed &	Fixed::operator= (Fixed const & rhs)
{
	if (log_messages)
		std::cout << "Assignation operator called." << std::endl;
	if (this != &rhs)
	{
		this->_fixed_point_value = rhs.getRawBits();
	}
	return *this;
}

Fixed & Fixed::operator= (const double d)
{
	if (log_messages)
		std::cout << "Assignation to double operation." << std::endl;
	_fixed_point_value = d * (1 << _n_fractional_bits);
	return *this;
}

std::ostream &	operator<< (std::ostream & o, Fixed const & fixed)
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
	_fixed_point_value = static_cast<int>(raw);
	return ;
}

Fixed::Fixed(const int i)
{
	if (log_messages)
		std::cout << "Int constructor called." << std::endl;
	_fixed_point_value = i << _n_fractional_bits;
	return ;
}

Fixed::Fixed(const float f)
{
	if (log_messages)
		std::cout << "Float constructor called." << std::endl;
	_fixed_point_value = f * (1 << _n_fractional_bits);
	return ;
}

Fixed::Fixed(const double d)
{
	if (log_messages)
		std::cout << "Float constructor called." << std::endl;
	_fixed_point_value = d * (1 << _n_fractional_bits);
	return ;
}

int	Fixed::toInt(void) const
{
	return _fixed_point_value >> _n_fractional_bits;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(_fixed_point_value) / static_cast<float>(1 << _n_fractional_bits);
}

bool Fixed::operator> (Fixed const & rhs) const
{
	return toFloat() > rhs.toFloat() ? 1 : 0;
}

bool Fixed::operator< (Fixed const & rhs) const
{
	return toFloat() < rhs.toFloat() ? 1 : 0;
}

bool Fixed::operator>= (Fixed const & rhs) const
{
	return toFloat() >= rhs.toFloat() ? 1 : 0;
}

bool Fixed::operator<= (Fixed const & rhs) const
{
	return toFloat() <= rhs.toFloat() ? 1 : 0;
}

bool Fixed::operator== (Fixed const & rhs) const
{
	return toFloat() == rhs.toFloat() ? 1 : 0;
}

bool Fixed::operator!= (Fixed const & rhs) const
{
	return toFloat() != rhs.toFloat() ? 1 : 0;
}

const Fixed Fixed::operator+ (Fixed const & rhs) const
{
	return Fixed(toFloat() + rhs.toFloat());
}

const Fixed Fixed::operator- (Fixed const & rhs) const
{
	return Fixed(toFloat() -  rhs.toFloat());
}

const Fixed Fixed::operator* (Fixed const & rhs) const
{
	return Fixed(toFloat() * rhs.toFloat());
}

const Fixed Fixed::operator/ (Fixed const & rhs) const
{
	return Fixed(toFloat() / rhs.toFloat());
}

Fixed & Fixed::max(const Fixed & a, const Fixed & b)
{
	return const_cast<Fixed &>(a.toFloat() > b.toFloat() ? a : b);
}

Fixed & Fixed::min(const Fixed & a, const Fixed & b)
{
	return const_cast<Fixed &>(a.toFloat() < b.toFloat() ? a : b);
}

Fixed & Fixed::operator++ ()
{
	setRawBits(getRawBits() + 1);
	return *this;
}

Fixed Fixed::operator++ (int)
{
	Fixed old(*this);
	operator++();
	return old; // Observed old being destructed very soon but at parents scope.
}

Fixed & Fixed::operator-- ()
{
	setRawBits(getRawBits() - 1);
	return *this;
}

Fixed Fixed::operator-- (int)
{
	Fixed old(*this);
	operator--();
	return old; // Observed old being destructed very soon but at parents scope.
}
