/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:59:59 by fde-capu          #+#    #+#             */
/*   Updated: 2021/06/24 08:44:35 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# define FRACT_BITS	8

#include <iostream>

class Fixed
{
	private:
		int					_fixed_point_value;
		static const int	_n_fractional_bits = FRACT_BITS;
	public:
		static bool log_messages;
		Fixed(void);
		Fixed(Fixed const & src);
		Fixed(const int i);
		Fixed(const float f);
		Fixed(const double f);
		Fixed &	operator= (Fixed const & rhs);
		Fixed &	operator= (const double);
		~Fixed(void);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;
		bool operator> (Fixed const & rhs) const;
		bool operator< (Fixed const & rhs) const;
		bool operator>= (Fixed const & rhs) const;
		bool operator<= (Fixed const & rhs) const;
		bool operator== (Fixed const & rhs) const;
		bool operator!= (Fixed const & rhs) const;
		const Fixed operator+ (Fixed const & rhs) const;
		const Fixed operator- (Fixed const & rhs) const;
		const Fixed operator* (Fixed const & rhs) const;
		const Fixed operator/ (Fixed const & rhs) const;
		Fixed & operator++ ();
		Fixed operator++ (int);
		Fixed & operator-- ();
		Fixed operator-- (int);
		static Fixed & min(const Fixed & a, const Fixed & b);
		static Fixed & max(const Fixed & a, const Fixed & b);
};

std::ostream &	operator<< (std::ostream & o, Fixed const & i);

#endif
