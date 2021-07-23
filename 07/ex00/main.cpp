/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu </var/mail/fde-capu>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 10:02:15 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/23 12:08:47 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>
#include "Awesome.hpp"

std::ostream & operator << (std::ostream & o, Awesome & self)
{
	o << *reinterpret_cast<int*>(&self);
	return o;
}

int main( void ) {
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	Awesome xx(2);
	Awesome yy(4);
	std::cout << xx << ":" << yy << std::endl;
	::swap(xx, yy);
	std::cout << xx << ":" << yy << std::endl;
	Awesome min = ::min(xx, yy);
	std::cout << "min:" << min << std::endl;
	Awesome max = ::max(xx, yy);
	std::cout << "max:" << max << std::endl;

	return 0;
}

