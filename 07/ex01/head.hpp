/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 12:14:44 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/27 11:32:27 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_HPP
# define HEAD_HPP

# include <cstddef>
# include "iter.hpp"
# include <iostream>
# include <sstream>
# include <iomanip>
# include <stdint.h>

void void_function_no_args();
int int_function_no_args();
void mymain();

template<typename T>
void void_templated_fun_argtype_equals(T x)
{
	// Shows local scope address (x is a copy of x), so it is all the same.
	void * address = static_cast<void *>(&x);
	std::cout << "void_templated_fun_argtype_equals(" << x << "::" << address << ") called." << std::endl;
	return ;
}

template<typename T>
void void_templated_fun_argtype_ref_to_same(T & x)
{
	// Shows reference address.
	void * address = static_cast<void *>(&x);
	std::cout << "void_templated_fun_argtype_ref_to_same(" << x << "::" << address << ") called." << std::endl;
	return ;
}

template<typename T>
void hex_dump(T & block)
{
	char * byte;
	std::size_t address = reinterpret_cast<std::size_t>(&block);
	std::stringstream dump;
	unsigned long hex_val;

	dump << std::hex << std::setfill('0');
	byte = reinterpret_cast<char *>(&block);
	dump << "0x" << address << "\t";
	for (size_t i = 0; i < sizeof(T*); i++)
	{
		if (i >= sizeof(T)) break;
		hex_val = static_cast<unsigned char>(*(byte + i));
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
	::iter(array, array_length, void_templated_fun_argtype_equals<T>);
	std::cout << "---" << std::endl;
	::iter(array, array_length, void_templated_fun_argtype_ref_to_same<T>);
	std::cout << "---" << std::endl;
	::iter(array, array_length, hex_dump<T>);
	std::cout << "===" << std::endl;
	std::cout << std::endl;
}

#endif
