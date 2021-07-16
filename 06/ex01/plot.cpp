/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 11:34:47 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/16 11:34:47 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include "header.hpp"

void hex_dump(const s_block &block_as_struct)
{
	char * byte;
	std::size_t address_str_a = reinterpret_cast<std::size_t>(&block_as_struct.str_a);
	std::size_t address_r_int = reinterpret_cast<std::size_t>(&block_as_struct.r_int);
	std::size_t address_str_b = reinterpret_cast<std::size_t>(&block_as_struct.str_b);
	std::stringstream dump;
	unsigned char hex_val;

	dump << std::hex << std::setfill('0');
	byte = (char *)(&block_as_struct.str_a);
	dump << "0x" << address_str_a << "\t";
	for (int i = 0; i < 8; i++)
	{
		unsigned hex_val = static_cast<unsigned char>(*(byte + i));
		dump << std::setw(2) << hex_val << " ";
	}
	dump << std::endl;
	byte = (char *)(&block_as_struct.r_int);
	dump << "0x" << address_r_int << "\t";
	for (int i = 0; i < 4; i++)
	{
		unsigned hex_val = static_cast<unsigned char>(*(byte + i));
		dump << std::setw(2) << hex_val << " ";
	}
	dump << std::endl;
	byte = (char *)(&block_as_struct.str_b);
	dump << "0x" << address_str_b << "\t";
	for (int i = 0; i < 8; i++)
	{
		unsigned hex_val = static_cast<unsigned char>(*(byte + i));
		dump << std::setw(2) << hex_val << " ";
	}
	dump << std::endl;
	std::cout << dump.str();
	return ;
}

void plot(void *block_as_void, std::string title)
{
	plot(reinterpret_cast<s_block *>(block_as_void), title);
	return ;
}

void plot(Data *block_as_data, std::string title)
{
	plot(reinterpret_cast<s_block *>(block_as_data), title);
	return ;
}

void plot(Data &block_as_data_ref, std::string title)
{
	plot(reinterpret_cast<s_block *>(&block_as_data_ref), title);
	return ;
}

void plot(s_block *block_as_struct, std::string title)
{
	std::string *	ptr_str_a = block_as_struct->str_a;
	int *			ptr_r_int = &block_as_struct->r_int;
	std::string *	ptr_str_b = block_as_struct->str_b;

	std::size_t address_block =			reinterpret_cast<std::size_t>(block_as_struct);
	std::size_t address_str_a =			reinterpret_cast<std::size_t>(&block_as_struct->str_a);
	std::size_t address_str_a_string =	reinterpret_cast<std::size_t>(ptr_str_a);
	std::size_t address_r_int =			reinterpret_cast<std::size_t>(ptr_r_int);
	std::size_t address_str_b =			reinterpret_cast<std::size_t>(&block_as_struct->str_b);
	std::size_t address_str_b_string =	reinterpret_cast<std::size_t>(ptr_str_b);
	std::size_t padding[3] = {
		address_str_a - address_block,
		address_r_int - address_str_a,
		address_str_b - address_r_int	
	};
	std::cout << "/:::::::::::::::::::::::::::::::::::::::::\\" << std::endl;
	std::cout << "0x" << std::hex << address_block << " :: " << title << std::endl;
	std::cout << "\t\t\t\t/---------\\" << std::endl;
	std::cout << "+" << padding[0] << "\t0x" << std::setw(10) << std::left << address_str_a << " (" << sizeof(ptr_str_a) << ")" <<	"\t| str_a * |---> 0x" << address_str_a_string << ": \"" << *ptr_str_a << "\"" << std::endl;
	std::cout << "+" << padding[1] << "\t0x" << std::setw(10) << std::left << address_r_int << " (" << sizeof(*ptr_r_int) << ")" <<	"\t| int ### | ==  " << std::dec << *ptr_r_int << std::hex << std::endl;
	std::cout << "+" << padding[2] << "\t0x" << std::setw(10) << std::left << address_str_b << " (" << sizeof(ptr_str_b) << ")" <<	"\t| str_b * |---> 0x" << address_str_b_string << ": \"" << *ptr_str_b << "\"" << std::endl;
	std::cout << "Total size: " << std::dec << sizeof(*block_as_struct) << "\t\t\t\\---------/" << std::endl;
	hex_dump(*block_as_struct);
	std::cout << "\\:::::::::::::::::::::::::::::::::::::::::/" << std::endl << std::endl;
	return ;
}
