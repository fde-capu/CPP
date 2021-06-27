/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu </var/mail/fde-capu>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 10:50:08 by fde-capu          #+#    #+#             */
/*   Updated: 2021/06/27 14:39:22 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include "iter.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>

void void_function_no_args()
{
	std::cout << "void_function_no_args() called." << std::endl;
	return ;
}

int int_function_no_args()
{
	std::cout << "int_function_no_args() called." << std::endl;
	return 42;
}

template<typename T>
void void_function_argtype_equals(T x)
{
	std::cout << "void_function_argtype_equals(" << x << ") called." << std::endl;
	return ;
}

template<typename T>
void void_function_argtype_ref_to_type_equals(T & x)
{
	std::cout << "void_function_argtype_ref_to_type_equals(" << x << ") called." << std::endl;
	return ;
}

template<typename T>
void hex_dump(T & block)
{
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

template<typename T>
void test(T * array, size_t array_length, std::string title)
{
	std::cout << title << std::endl << "---" << std::endl;;
	::iter(array, array_length, void_function_no_args);
	std::cout << "---" << std::endl;
	::iter(array, array_length, int_function_no_args);
	std::cout << "---" << std::endl;
	::iter(array, array_length, void_function_argtype_equals<T>);
	std::cout << "---" << std::endl;
	::iter(array, array_length, void_function_argtype_ref_to_type_equals<T>);
	std::cout << "---" << std::endl;
	::iter(array, array_length, hex_dump<T>);
	std::cout << "---" << std::endl;
	::iter(array, array_length, int_function_no_args);
	std::cout << "===" << std::endl;
	std::cout << std::endl;
}

void f_a() { std::cout << "function a" << std::endl; }
void f_b() { std::cout << "function b" << std::endl; }
void f_c() { std::cout << "function c" << std::endl; }

int main()
{
	{
		const size_t array_length = 4;
		int array[array_length] = {42, 142, 123, -42};
		test(array, array_length, "int array[4]");
	}
	{
		const size_t array_length = 4;
		int array[array_length] = {42, 142, 123, -42};
		test(array, array_length, "int array[4]");
	}
	{
		const size_t array_length = 5;
		std::string array[array_length] = {"ABC", "forty two", "anything", "", "0"};
		test(array, array_length, "std::string array[5]");
	}
	{
		int arr_a[3] = {8, 1, 6};
		int arr_b[3] = {3, 5, 7};
		int arr_c[3] = {4, 9, 2};
		const size_t array_length = 3;
		int * array[array_length] = {arr_a, arr_b, arr_c};
		test(array, array_length, "Array of arrays");
	}
	{
		const size_t array_length = 3;
		void (*array[array_length])() = {f_a, f_b, f_c};
		test(array, array_length, "Array of void functions");
	}
	{
		std::cout << "More tests" << std::endl << "---" << std::endl;
		const size_t array_length = 4;
		int array[array_length] = {42, 142, 123, -42};
		// For sake of explanation: for templated functions:
		// ::iter(array, array_length, hex_dump); // This doesn't work.
		::iter(array, array_length, hex_dump<int>); // This is instantiated.
		std::cout << "---" << std::endl;
		// In the following case, the function is instantiated
		// with another type than array is.
		::iter(array, array_length, hex_dump<char>);
		std::cout << "---" << std::endl;
		::iter(array, array_length, void_function_argtype_ref_to_type_equals<char>);
//		::iter(array, array_length, void_function_argtype_equals<char>);
	}
	return 0;
}
