/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu </var/mail/fde-capu>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 10:50:08 by fde-capu          #+#    #+#             */
/*   Updated: 2021/06/24 18:40:01 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include "iter.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>

void some_function_without_arguments()
{
	std::cout << "some_function_without_arguments() called." << std::endl;
	return ;
}

template<typename T>
void some_function_with_one_arg(T x)
{
	std::cout << "some_function_with_one_arg(" << x << ") called." << std::endl;
	return ;
}

template<typename T>
void some_function_with_one_ref(T & x)
{
	std::cout << "some_function_with_one_ref(" << x << ") called." << std::endl;
	return ;
}

template<typename T>
void hex_dump(T & block)
{
	std::cout << "hex_dump(" << block << ") called." << std::endl;
	char * byte;
	std::size_t address = reinterpret_cast<std::size_t>(&block);
	std::stringstream dump;

	dump << std::hex << std::setfill('0');
	byte = (char *)(&block);
	dump << "0x" << address << "\t";
	for (size_t i = 0; i < sizeof(T); i++)
	{
		unsigned hex_val = static_cast<unsigned char>(*(byte + i));
		dump << std::setw(2) << hex_val << " ";
	}
	dump << std::dec << std::endl;
	std::cout << dump.str();
	return ;
}

int main()
{
	size_t array_length = 4;
	int array[array_length];

	array[0] = 42;
	array[1] = 142;
	array[2] = 123;
	array[3] = -42;

	std::cout << std::endl << "::iter(array, array_length, some_function_without_arguments);" << std::endl;
	::iter(array, array_length, some_function_without_arguments);

	std::cout << std::endl << "::iter(array, array_length, some_function_with_one_arg<int>);" << std::endl;
	::iter(array, array_length, some_function_with_one_arg<int>); // <int> makes it instantiated.
//	::iter(array[0], array_length, some_function_with_one_arg); // Cannot infer template argument.

	std::cout << std::endl << "::iter(array, array_length, some_function_with_one_ref<int>);" << std::endl;
	::iter(array, array_length, some_function_with_one_ref<int>); // <int> is same type of array.
//	::iter(array[0], array_length, some_function_with_one_ref<char>); // Not prototyped. Function argument must be of same type as the array.

	std::cout << std::endl << "::iter(array, array_length, hex_dump<int>);" << std::endl;
	::iter(array, array_length, hex_dump<int>);

	return 0;
}
