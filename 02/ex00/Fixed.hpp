/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:59:59 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/19 14:59:59 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
	private:
		int					_fixed_point_value;
		static const int	_number_of_fractional_bits = 8;
	public:
		Fixed(void);
		Fixed(Fixed const & src);
		Fixed &	operator = (Fixed const & rhs);
		~Fixed(void);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

std::ostream &	operator << (std::ostream & o, Fixed const & i);

