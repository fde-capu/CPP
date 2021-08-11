/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_dump.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 08:35:16 by fde-capu          #+#    #+#             */
/*   Updated: 2021/08/05 08:39:08 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEX_DUMP_HPP
# define HEX_DUMP_HPP

# include <sstream>
# include <iomanip>

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

#endif
