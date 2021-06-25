/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 13:25:39 by fde-capu          #+#    #+#             */
/*   Updated: 2021/06/08 11:26:06 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cpp.hpp"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

int	validate_args(int argc, char ** argv)
{
	if (argc != 4)
		return log_ret("Bad argument count.", 0);
	if (!file_exists(argv[1]))
		return log_ret("Bad filename.", 0);
	std::string x(argv[2]);
	if (!x.length())
		return log_ret("Zero-length string 1.", 0);
	x = std::string (argv[3]);
	if (!x.length())
		return log_ret("Zero-length string 2.", 0);
	x = std::string (argv[1]).append(".replace");
	if (file_exists((char *)x.c_str()))
		return log_ret("File `.replace` already exists.", 0);
	return 1;
}

std::string	ft_replace(std::string line, std::string a, std::string b)
{
	std::ostringstream	out;
	for (int i = 0; i < (int)line.size(); i++)
	{
		if (0 == line.compare(i, a.size(), a))
		{
			out << b;
			i += a.size() - 1;
		}
		else
			out << line.at(i);
	}
	return out.str();
}

int	main(int argc, char **argv)
{
	if (!validate_args(argc, argv))
		return 1;
	std::ifstream	ifs(argv[1]);
	std::ofstream	ofs((std::string (argv[1]).append(".replace").c_str()));
	std::string		change_this(argv[2]);
	std::string		for_that(argv[3]);
	std::string		line;
	while (std::getline(ifs, line))
	{
		line = ft_replace(line, change_this, for_that);
		ofs << line << std::endl;
	}
	ifs.close();
	ofs.close();
	return 0;
}
