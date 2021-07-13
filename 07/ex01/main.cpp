/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu </var/mail/fde-capu>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 10:50:08 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/07 11:12:00 by fde-capu         ###   ########.fr       */
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
	std::cout << "void_function_argtype_equals(" << x << "::" << &x << ") called." << std::endl;
	return ;
}

template<typename T>
void void_function_argtype_ref_to_type_equals(T & x)
{
	std::cout << "void_function_argtype_ref_to_type_equals(" << x << "::" << &x << ") called." << std::endl;
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
	std::cout << "===" << std::endl;
	std::cout << std::endl;
}

void vf_a() { std::cout << "void function a" << std::endl; }
void vf_b() { std::cout << "void function b" << std::endl; }
void vf_c() { std::cout << "void function c" << std::endl; }

int if_a() { std::cout << "int function a" << std::endl; return 42; }
int if_b() { std::cout << "int function b" << std::endl; return 42; }
int if_c() { std::cout << "int function c" << std::endl; return 42; }

int main()
{
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
		int (*array[array_length])() = {if_a, if_b, if_c};
		test(array, array_length, "Array of int functions");
	}
	{
		const size_t array_length = 3;
		void (*array[array_length])() = {vf_a, vf_b, vf_c};
		test(array, array_length, "Array of void functions");
	}
	{
		std::cout << "More tests" << std::endl << "---" << std::endl;
		const size_t array_length = 4;
		int array[array_length] = {42, 142, 123, -42};
		// For sake of explanation:
		// subject.pdf states that iter() should work on instantiated templates.
		// ::iter(array, array_length, hex_dump); // This doesn't work...
		::iter(array, array_length, hex_dump<int>); // ...this is ok, instantiated.
		std::cout << "---" << std::endl;
		// In the following overloads, the function is instantiated
		// with another type than array is.
		::iter(array, array_length, void_function_argtype_ref_to_type_equals<char>);
		std::cout << "---" << std::endl;
		::iter(array, array_length, hex_dump<char>);
	}
	return 0;
}
