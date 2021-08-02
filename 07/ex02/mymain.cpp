/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymain.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 11:33:57 by fde-capu          #+#    #+#             */
/*   Updated: 2021/08/02 11:39:27 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <climits>
#include "Array.hpp"
#include "Awesome.hpp"

int mymain()
{
	std::cout << std::endl;


	std::cout << std::endl << "[ A ] Empty constructor." << std::endl;
	std::cout << " #	Array<int> foo1 = Array<int>();" << std::endl;
						Array<int> foo1 = Array<int>();
	std::cout << " ------> foo1.size(): " << foo1.size() << std::endl;


	std::cout << std::endl << "[ B ] Argument unsigned int constructor." << std::endl;
	std::cout << " #	Array<int> foo2(5);" << std::endl;
						Array<int> foo2(5);
	std::cout << " ------> foo2.size(): " << foo2.size() << std::endl;


	std::cout << std::endl << "[ C ] Copy constructor / Set value operator[]." << std::endl;
	std::cout << " #	Array<int>x(5);" << std::endl;
						Array<int>x(5);
	std::cout << " #	x[2] = 2;" << std::endl;
						x[2] = 2;
	std::cout << " ------> (x) " << x << std::endl;
	std::cout << " #	Array<int>y = Array<int>(x);" << std::endl;
						Array<int>y = Array<int>(x);
	std::cout << " ------> (y) " << y << std::endl;


	std::cout << std::endl << "[ D ] Deep copy demo / Set value operator[]." << std::endl;
	std::cout << " #	y[1] = 4;" << std::endl;
						y[1] = 4;
	std::cout << " ------> (x) " << x << std::endl;
	std::cout << " ------> (y) " << y << std::endl;
	std::cout << " #	x[4] = -42;" << std::endl;
						x[4] = -42;
	std::cout << " ------> (x) " << x << std::endl;
	std::cout << " ------> (y) " << y << std::endl;


	std::cout << std::endl << "[ E ] Get value operator[]." << std::endl;
	std::cout << " ------> x[2] : " << x[2] << std::endl;
	std::cout << " ------> x[4] : " << x[4] << std::endl;
	std::cout << " ------> y[1] : " << y[1] << std::endl;
	std::cout << " ------> y[0] : " << y[0] << std::endl;


	std::cout << std::endl << "[ F ] Other types. Stack." << std::endl;
	std::cout << "// Character 0 is NULL, hence the line breaks depending on shell interface." << std::endl;
	std::cout << " #	Array<char>c(4);" << std::endl;
						Array<char>c(4);
	std::cout << " ------> (c) " << c << std::endl;
	std::cout << " #	c[2] = 'X';" << std::endl;
						c[2] = 'X';
	std::cout << " #	c[3] = 42;" << std::endl;
						c[3] = 42;
	std::cout << " ------> (c) " << c << std::endl;


	std::cout << std::endl << "[ G ] Other types. Heap." << std::endl;
	std::cout << " #	Array<char>*cheap = new Array<char>(4);" << std::endl;
						Array<char>*cheap = new Array<char>(4);
	std::cout << " ------> (c) " << *cheap << std::endl;
	std::cout << " #	(*cheap)[2] = '-';" << std::endl;
						(*cheap)[2] = '-';
	std::cout << " #	(*cheap)[3] = '-';" << std::endl;
						(*cheap)[3] = '-';
	std::cout << " ------> (c) " << *cheap << std::endl;
	delete cheap;


	std::cout << std::endl << "[ H ] Other types, float for example." << std::endl;
	Array<float>afloat(5);
	std::cout << " ------> (afloat) " << afloat << std::endl;
	afloat[2] = 42.042f;
	std::cout << " ------> (afloat) " << afloat << std::endl;


	std::cout << std::endl << "[ I ] Other types, std::string." << std::endl;
	Array<std::string>str(5);
	std::cout << " ------> (str) " << str << std::endl;
	str[2] = "Don't Panic";
	std::cout << " ------> (str) " << str << std::endl;


	std::cout << std::endl << "[ J ] Othere types, Awesome from ex00 mixed with ex01." << std::endl;
	Array<Awesome>gr8(5);
	std::cout << " ------> " << gr8 << std::endl;
	gr8[2] = 555;
	std::cout << " ------> " << gr8 << std::endl;
	std::cout << " ------> " << gr8[2] << std::endl;


	std::cout << std::endl << "[ K ] Array<const T>." << std::endl;
	Array<const int> foo3 = Array<const int>(5);
//	foo3[2] = 42; // Does not compile (constness).
	std::cout << foo3 << std::endl;
	std::cout << "--> [2]: " << foo3[2] << std::endl; // Retrieves.

	Array<const int> foo3cp(foo3);
//	foo3cp[2] = 42; // Does not compile (constness).
	std::cout << foo3cp << std::endl;
	std::cout << "--> [2]: " << foo3cp[2] << std::endl;

	Array<const std::string> foo4 = Array<const std::string>(5);
//	foo4[2] = "Don't Panic"; // Does not compile (no overload).
	std::cout << foo4 << std::endl;
	std::cout << "\"" << foo4[2] << "\" <- (empty string)" << std::endl;

	Array<const Awesome> foo5 = Array<const Awesome>(5);
//	foo5[2] = 4242; // Does not compile (no overload).
	std::cout << foo5 << std::endl;
	std::cout << foo5[2] << std::endl;


	std::cout << std::endl << "[ Z ] Out of range." << std::endl;
	std::cout << "// x[77] = 11;" << std::endl;
	try { x[77] = 11; } catch(const std::exception&e) { std::cout << e.what() << std::endl; }
	std::cout << "// x[-1] = 66;" << std::endl;
	try { x[-1] = 66; } catch(const std::exception&e) { std::cout << e.what() << std::endl; }

	std::cout << std::endl << std::endl;
	return 0;
}
