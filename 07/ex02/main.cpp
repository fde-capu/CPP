/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:40:55 by fde-capu          #+#    #+#             */
/*   Updated: 2021/06/29 18:06:33 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
	std::cout << "My tests:" << std::endl;
	{
		Array<int> foo1 = Array<int>();
		std::cout << "foo1.size(): " << foo1.size() << std::endl;
		Array<int> foo2 = Array<int>(5);
		std::cout << "foo2.size(): " << foo2.size() << std::endl;
		for (size_t i = 0; i < 5; i++)
			std::cout << "foo2[" << i << "]: " << foo2[i] << std::endl;
		try
		{
			std::cout << "foo2[-1]: " << foo2[-1] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << "std::exception thrown: " << e.what() << std::endl;
		}
		try
		{
			std::cout << "foo2[7]: " << foo2[7] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << "std::exception thrown: " << e.what() << std::endl;
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
