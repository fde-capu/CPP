/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:52:09 by fde-capu          #+#    #+#             */
/*   Updated: 2021/06/24 08:57:23 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	std::cout << ">>> Subject.pdf test (it ommits event logs):" << std::endl;
	{
		Fixed a;

		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}
	std::cout << std::endl << ">>> Expanded tests:" << std::endl;
	{
		Fixed::log_messages = 0; // Bonus.
		Fixed a;

		std::cout << a << std::endl;
		a = 4.33; // Assignation operator= (double) bonus.
		std::cout << "a: " << a << std::endl;
		Fixed const b(Fixed(5.05f) / Fixed(2.02)); // Constructor(double) bonus.
		std::cout << "b: " << b << std::endl;
		std::cout << "during --a: " << --a << std::endl;
		std::cout << "after --a: " << a << std::endl;
		std::cout << "during a--: " << a-- << std::endl;
		std::cout << "after: " << a << std::endl;
		std::cout << "min(a,b): " << Fixed::min( a, b ) << std::endl;
		std::cout << "a > b: " << (a > b) << std::endl;
		std::cout << "a < b: " << (a < b) << std::endl;
		Fixed const c(a);
		std::cout << "c(a): " << c << std::endl;
		std::cout << "a > c: " << (a > c) << std::endl;
		std::cout << "a < c: " << (a < c) << std::endl;
		std::cout << "a >= c: " << (a >= c) << std::endl;
		std::cout << "a <= c: " << (a <= c) << std::endl;
		std::cout << "a == b: " << (a == b) << std::endl;
		std::cout << "a == c: " << (a == c) << std::endl;
		std::cout << "a != b: " << (a != b) << std::endl;
		std::cout << "a != c: " << (a != c) << std::endl;
		std::cout << "a + b: " << a << " + " << b << ": " << (a + b) << std::endl;
		std::cout << "a - b: " << a << " - " << b << ": " << (a - b) << std::endl;
		std::cout << "a * b: " << a << " * " << b << ": " << (a * b) << std::endl;
		std::cout << "a / b: " << a << " / " << b << ": " << (a / b) << std::endl;
		std::cout << std::endl << "Arithmetic returns a Fixed at stack at the tiny scope (log_message on):" << std::endl;
		Fixed::log_messages = 1;
		std::cout << "a + c: " << a << " + " << c << ": " << (a + c) << std::endl;
		Fixed::log_messages = 0;
		std::cout << std::endl;
		std::cout << "a + b - c: " << a << " + " << b << " - " << c << ": " << (a + b - c) << std::endl;
		std::cout << "a + b / c: " << a << " + " << b << " / " << c << ": " << (a + b / c) << std::endl;
		// Not implemented:
		// +=, -=, *=, /=	_       _
		// Nobody asked.	 \_Oo,_/
	}
	return 0;
}
