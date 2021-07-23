/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymain.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 11:33:57 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/23 14:31:45 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <climits>
#include "Array.hpp"

int mymain()
{
	std::cout << std::endl;


	std::cout << std::endl << "[ A ] Empty constructor." << std::endl;
	std::cout << " #	Array<int> foo1 = Array<int>();" << std::endl;
						Array<int> foo1 = Array<int>();
	std::cout << " ------> foo1.size(): " << foo1.size() << std::endl;


	std::cout << std::endl << "[ B ] unsigned int constructor." << std::endl;
	std::cout << " #	Array<int> foo2 = Array<int>(5);" << std::endl;
						Array<int> foo2 = Array<int>(5);
	std::cout << " ------> foo2.size(): " << foo2.size() << std::endl;


	{
		std::cout << std::endl << "[ C ] {Scope} Empty instantiation." << std::endl;
		std::cout << " #	Array<int>*x = new Array<int>();" << std::endl;
							Array<int>*x = new Array<int>();
		std::cout << " ------> " << *x << std::endl;
		delete x;
	}


	{
		std::cout << std::endl << "[ D ] {Scope} Numbered instantiation." << std::endl;
		std::cout << " #	Array<int>*x = new Array<int>(3);" << std::endl;
							Array<int>*x = new Array<int>(3);
		std::cout << " ------> " << *x << std::endl;
		delete x;
	}


	std::cout << std::endl << "[ E ] Copy constructor." << std::endl;
	std::cout << " #	Array<int>x = Array<int>(5);" << std::endl;
						Array<int>x = Array<int>(5);
	std::cout << " #	x[2] = 2;" << std::endl;
						x[2] = 2;
	std::cout << " ------> (x) " << x << std::endl;
	std::cout << " #	Array<int>y = Array<int>(x);" << std::endl;
						Array<int>y = Array<int>(x);
	std::cout << " ------> (y) " << y << std::endl;


	std::cout << std::endl << "[ F ] Deep copy demo / Set value operator[]." << std::endl;
	std::cout << " #	y[1] = 4;" << std::endl;
						y[1] = 4;
	std::cout << " ------> (x) " << x << std::endl;
	std::cout << " ------> (y) " << y << std::endl;
	std::cout << " #	x[4] = -42;" << std::endl;
						x[4] = -42;
	std::cout << " ------> (x) " << x << std::endl;
	std::cout << " ------> (y) " << y << std::endl;


	std::cout << std::endl << "[ G ] Get value operator[]." << std::endl;
	std::cout << " ------> x[2] : " << x[2] << std::endl;
	std::cout << " ------> x[4] : " << x[4] << std::endl;
	std::cout << " ------> y[1] : " << y[1] << std::endl;
	std::cout << " ------> y[0] : " << y[0] << std::endl;


	std::cout << std::endl << "[ HA ] Other types. Stack." << std::endl;
	std::cout << "// Character 0 is NULL, hence the line breaks." << std::endl;
	std::cout << " # Array<char>c = new Array<char>(4);" << std::endl;
	Array<char>c = Array<char>(4);
	std::cout << " ------> (c) " << c << std::endl;
	std::cout << " #	c[2] = 'X';" << std::endl;
						c[2] = 'X';
	std::cout << " #	c[3] = 42;" << std::endl;
						c[3] = 42;
	std::cout << " ------> (c) " << c << std::endl;


	std::cout << std::endl << "[ HB ] Other types. Heap." << std::endl;
	std::cout << " # Array<char>*cheap = new Array<char>(4);" << std::endl;
	Array<char>*cheap = new Array<char>(4);
	std::cout << " ------> (c) " << *cheap << std::endl;
	std::cout << " #	(*cheap)[2] = '-';" << std::endl;
						(*cheap)[2] = '-';
	std::cout << " #	(*cheap)[3] = '-';" << std::endl;
						(*cheap)[3] = '-';
	std::cout << " ------> (c) " << *cheap << std::endl;
	delete cheap;

	std::cout << std::endl << "[ HC ] Other types, float for example." << std::endl;
	Array<float>afloat = Array<float>(5);
	std::cout << " ------> (afloat) " << afloat << std::endl;
	afloat[2] = 42.042f;
	std::cout << " ------> (afloat) " << afloat << std::endl;

	std::cout << std::endl << "[ HD ] Other types, std::string, complex." << std::endl;
	Array<std::string>str = Array<std::string>(5);
	std::cout << " ------> (str) " << str << std::endl;
	str[2] = "Don't Panic";
	std::cout << " ------> (str) " << str << std::endl;

	std::cout << std::endl << "[ Z ] Out of range." << std::endl;
	std::cout << "// x[7] = 11;" << std::endl;
	// x[7] = 11;
	std::cout << "// x[-1] = 7;" << std::endl;
	// x[-1] = 7;

	std::cout << std::endl << std::endl;
	return 0;
}
