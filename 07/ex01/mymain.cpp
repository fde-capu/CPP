/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymain.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 12:57:12 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/23 14:22:20 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.hpp"

void void_function_no_args() { std::cout << "void_function_no_args() called." << std::endl; }
int int_function_no_args() { std::cout << "int_function_no_args() called." << std::endl; return 42; }
void vf_a() { std::cout << "void function a" << std::endl; }
void vf_b() { std::cout << "void function b" << std::endl; }
void vf_c() { std::cout << "void function c" << std::endl; }
int if_a() { std::cout << "int function a" << std::endl; return 42; }
int if_b() { std::cout << "int function b" << std::endl; return 42; }
int if_c() { std::cout << "int function c" << std::endl; return 42; }

void mymain()
{
	{
		const size_t array_length = 4;
		int array[array_length] = {42, 142, 123, -42};
		test(array, array_length, "int array[4] = {42, 142, 123, -42}");
	}
	{
		const size_t array_length = 4;
		char array[array_length] = {'4', '2', 'S', 'P'};
		test(array, array_length, "char array[4] = {'4', '2', 'S', 'P'}");
	}
	{
		const size_t array_length = 5;
		std::string array[array_length] = {"ABC", "forty two", "anything", "", "0"};
		test(array, array_length, "std::string array[5] = {\"ABC\", \"forty two\", \"anything\", \"\", \"0\"}");
	}
	{
		int arr_a[3] = {8, 1, 6};
		int arr_b[3] = {3, 5, 7};
		int arr_c[3] = {4, 9, 2};
		const size_t array_length = 3;
		int * array[array_length] = {arr_a, arr_b, arr_c};
		test(array, array_length, "Array of arrays {arr_a, arr_b, arr_c}");
	}
	{
		const size_t array_length = 3;
		int (*array[array_length])() = {if_a, if_b, if_c}; // if: int function
		test(array, array_length, "Array of int functions {if_a, if_b, if_c}");
	}
	{
		const size_t array_length = 3;
		void (*array[array_length])() = {vf_a, vf_b, vf_c}; // vf: void function
		test(array, array_length, "Array of void functions {vf_a, vf_b, vf_c}");
	}
	{
		std::cout << "More tests" << std::endl << "---" << std::endl;
		const size_t array_length = 4;
		int array[array_length] = {42, 142, 123, -42};
		// subject.pdf states that iter() should work on instantiated templates.
		// ::iter(array, array_length, hex_dump); // This would not work...
		::iter(array, array_length, hex_dump<int>); // ...this is ok, instantiated.
	}
	std::cout << std::endl << "Awesome output:" << std::endl;
}
