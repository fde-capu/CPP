/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymain.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 11:33:57 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/22 13:29:55 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <climits>
#include "Array.hpp"

int mymain()
{
	std::cout << std::endl;
	std::cout << "My Main:" << std::endl;
	std::cout << "========" << std::endl;

	std::cout << std::endl << "[ A ]" << std::endl;
	std::cout << "// Construction with no parameter: creates an empty array." << std::endl;
	std::cout << " #	Array<int> foo1 = Array<int>();" << std::endl;
						Array<int> foo1 = Array<int>();
	std::cout << " ------> foo1.size(): " << foo1.size() << std::endl;

	std::cout << std::endl << "[ B ]" << std::endl;
	std::cout << "// Construction with an unsigned int n as a parameter:" << std::endl;
	std::cout << "// creates an array of n elements." << std::endl;
	std::cout << " #	Array<int> foo2 = Array<int>(5);" << std::endl;
						Array<int> foo2 = Array<int>(5);
	std::cout << " ------> foo2.size(): " << foo2.size() << std::endl;

	std::cout << std::endl << "[ D ]" << std::endl;
	std::cout << "// Breaks:" << std::endl;
	std::cout << " #	// Array<int>x = Array<int>(LONG_MAX);" << std::endl;
						// Array<int>x = Array<int>(LONG_MAX);

	{
		std::cout << std::endl << "[ E ]" << std::endl;
		std::cout << " #	int * a = new int();" << std::endl;
							int * a = new int();
		std::cout << " ------> " << *a << std::endl;
		std::cout << " #	Array<int>*x = new Array<int>();" << std::endl;
							Array<int>*x = new Array<int>();
		std::cout << " ------> " << *x << std::endl;
	}

	{
		std::cout << std::endl << "[ F ]" << std::endl;
		std::cout << " #	int * a = new int(3);" << std::endl;
							int * a = new int(3);
		std::cout << " ------> " << *a << std::endl;
		std::cout << " #	Array<int>*x = new Array<int>(3);" << std::endl;
							Array<int>*x = new Array<int>(3);
		std::cout << " ------> " << *x << std::endl;
	}

	std::cout << "===" << std::endl;
	Array<int>x = Array<int>(5);
	std::cout << x << std::endl;
	Array<int> y = Array<int>(x);
	std::cout << y << std::endl;

	return 0;
}
