/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:40:55 by fde-capu          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/07/11 09:52:54 by fde-capu         ###   ########.fr       */
=======
/*   Updated: 2021/07/08 08:25:58 by fde-capu         ###   ########.fr       */
>>>>>>> dd9a8691ac7bf47e07dfacb94158a743237b8fda
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <climits>
#include "Array.hpp"
#include <csignal>

#define MAX_VAL 750

void	test (int signal_number)
{
	std::cout << "TEST? - " << signal_number << " -" << std::endl;
}

int main(int, char**)
{
	std::cout << "My tests:" << std::endl;
	{
		// Construction with no parameter: creates an empty array.
		Array<int> foo1 = Array<int>();
		// Array<int> foo2 = Array<int>(-5); // -Wconversion prevent.
		std::cout << "[ A ] foo1.size(): " << foo1.size() << std::endl;

		// Construction with an unsigned int n as a parameter:
		// creates an array of n elements, initialized by default.
		Array<int> foo2 = Array<int>(5); // int casts to unsigned int
		std::cout << "[ B ] foo2.size(): " << foo2.size() << std::endl;

		// Construction with other type than unsigned int n:
		// Exception handled. Bonus?

//		std::set_terminate (test);
		std::signal(SIGABRT, &test);
		try
		{
			std::cout << "[ C ] # Array<int> foo_fail = Array<int>(-5);" << std::endl;
			Array<int> foo_fail = Array<int>(-5);
			// Never gets to this line.
		}
		catch(const std::exception &e)
		{
			std::cout << "[ D ] got: " << e.what() << std::endl;
		}
		// Never get to this line.
//		catch()
//		{
//			std::cout << "!!!" << std::endl;
//		}

		Array<int> foo3 = Array<int>(static_cast<char>(88)); // This is fine.
		std::cout << "[ E ] foo3.size(): " << foo3.size() << std::endl;

		std::cout << "[ F ] # Array<int> foo4 = Array<int>(static_cast<long>(1)); // This is fine. ::" << std::endl;
		Array<int> foo4 = Array<int>(static_cast<long>(1)); // This is fine.
		std::cout << "[ G ] foo4.size(): " << foo4.size() << std::endl;

		try
		{
			std::cout << "[ H ] # Array<int> foo_fail = Array<int>(static_cast<long>(LONG_MAX));" << std::endl;
			Array<int> foo_fail = Array<int>(static_cast<long>(LONG_MAX));
			std::cout << "[ I ] This line." << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cout << "[ J ] got: " << e.what() << std::endl;
		}






		for (size_t i = 0; i < 5; i++)
			std::cout << "[ A ] foo2[" << i << "]: " << foo2[i] << std::endl;
		try
		{
			std::cout << "[ A ] foo2[-1]: " << foo2[-1] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << "[ A ] std::exception thrown: " << e.what() << std::endl;
		}
		try
		{
			std::cout << "[ A ] foo2[7]: " << foo2[7] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << "[ A ] std::exception thrown: " << e.what() << std::endl;
		}
	}
//	Array<int> numbers(MAX_VAL);
//	int* mirror = new int[MAX_VAL];
//	srand(time(NULL));
//	for (int i = 0; i < MAX_VAL; i++)
//	{
//		const int value = rand();
//		numbers[i] = value;
//		mirror[i] = value;
//	}
//	//SCOPE
//	{
//		Array<int> tmp = numbers;
//		Array<int> test(tmp);
//	}
//
//	for (int i = 0; i < MAX_VAL; i++)
//	{
//		if (mirror[i] != numbers[i])
//		{
//			std::cerr << "didn't save the same value!!" << std::endl;
//			return 1;
//		}
//	}
//	try
//	{
//		numbers[-2] = 0;
//	}
//	catch(const std::exception& e)
//	{
//		std::cerr << e.what() << '\n';
//	}
//	try
//	{
//		numbers[MAX_VAL] = 0;
//	}
//	catch(const std::exception& e)
//	{
//		std::cerr << e.what() << '\n';
//	}
//
//	for (int i = 0; i < MAX_VAL; i++)
//	{
//		numbers[i] = rand();
//	}
//	delete [] mirror;//
	return 0;
}
