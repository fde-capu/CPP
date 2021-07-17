/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 11:34:47 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/17 09:27:37 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Notes:
**
** As can be seen on the `plot`, the `int` variable
** actually maps to 8 bytes. This is due to memory
** alignment.
*/

#include "header.hpp"
#include "Data.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <limits.h>
#include <stdint.h>

std::string random_string(std::string fixed, int len)
{
	std::stringstream out;
	out << fixed;
	for (int i = 0; i < len; i++)
		out << static_cast<unsigned char>((rand() % ('~' - ' ')) + ' ');
	return out.str();
}

int random_int(int min, int max)
{
	return min + (rand() % (max - min + 1));
}

uintptr_t serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data * deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}

Data * deserialize_new(uintptr_t raw)
{
	return new Data(*reinterpret_cast<Data *>(raw));
}

int main()
{
	srand(static_cast<unsigned int>(time(0))); // Seed.

	std::cout << "Do not forget to include the Data structure you used." << std::endl << std::endl;
	std::cout << "```" << std::endl;
	system("cat Data.hpp | tail -n 20 | head -n -4");
	std::cout << "```" << std::endl;

	std::cout << "### Data * deserialize(uintptr_t raw);" << std::endl;
	{
		std::cout << "You must create a valid data structure." << std::endl;
		Data * data = new Data();
		plot(data, "data");

		std::cout << "Take a Data address use serialize on it." << std::endl;
		uintptr_t address = serialize(data);
		std::cout << "uintptr_t address == " << address << std::endl << std::endl;

		std::cout << "Send the return value in deserialize." << std::endl;
		std::cout << "Data * re_data = deserialize(" << address << ");" << std::endl << std::endl;
		Data * re_data = deserialize(address);
		plot(re_data, "re_data");

		std::cout << "Check if the return value is equal to the first pointer." << std::endl;

		std::cout << "(data == re_data) == ("
			<< data << " == " << re_data << ") == "
			<< (data == re_data) << std::endl;

		std::cout << "(*data == *re_data) == ("
			<< *data << " == " << *re_data << ") == "
			<< (*data == *re_data) << std::endl; // `Data::operator==` implemented.

		std::cout << "uintptr_t new_address = serialize(re_data);" << std::endl;
		uintptr_t new_address = serialize(re_data);
		std::cout << "uintptr_t new_address == " << new_address << std::endl << std::endl;

		delete data;
		// delete re_data; // re_data points to same data!
	}

	std::cout << "### Data * deserialize_new(uintptr_t raw);" << std::endl << std::endl;
	{
		std::cout << "You must create a valid data structure." << std::endl;
		Data * data = new Data();
		plot(data, "data");

		std::cout << "Take a Data address use serialize on it." << std::endl;
		uintptr_t address = serialize(data);
		std::cout << "uintptr_t address == " << address << std::endl << std::endl;

		std::cout << "Send the return value in deserialize." << std::endl;
		std::cout << "Data * re_data = deserialize(" << address << ");" << std::endl << std::endl;
		Data * re_data = deserialize_new(address);
		plot(re_data, "re_data");

		std::cout << "Check if the return value is equal to the first pointer." << std::endl;

		std::cout << "(data == re_data) == ("
			<< data << " == " << re_data << ") == "
			<< (data == re_data) << std::endl;

		std::cout << "(*data == *re_data) == ("
			<< *data << " == " << *re_data << ") == "
			<< (*data == *re_data) << std::endl;

		std::cout << "uintptr_t new_address = serialize(re_data);" << std::endl;
		uintptr_t new_address = serialize(re_data);
		std::cout << "uintptr_t new_address == " << new_address << std::endl << std::endl;

		delete data;
		delete re_data;
	}

	return 0;
}
