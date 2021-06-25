/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpp.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:44:06 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/14 23:51:19 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cpp.hpp"
#include <iostream>
#include <sstream>
#include <fstream>

int			log_ret(const char * msg, int ret_val)
{
	log (msg);
	return (ret_val);
}

void	log(const char * msg)
{
	std::cout << msg << std::endl;
	return ;
}

int	file_exists(char * file)
{
	std::ifstream infile(file);
	if (!infile.good())
		return 0;
	return 1;
}

int	ft_isnumber(const char *str)
{
	char	*p;
	char	*s;

	p = (char *)str;
	s = p;
	while ((*p) && ((*p == ' ') || (*p == '-') || (*p == '+')))
		p++;
	while ((*p) && (*p >= '0') && (*p <= '9'))
		p++;
	if (*p || p == s)
		return (0);
	return (1);
}

int	prompt_str(const char *txt, std::string *com)
{
	std::cout << txt << std::endl;
	std::cin.clear();
	getline(std::cin, *com);
	if (std::cin.eof() == 1)
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout << std::endl;
		return 0;
	}
	return 1;
}

std::string	ft_toUpper(std::string in)
{
	std::ostringstream	up;
	for (int i = 0; i < (int)in.size(); i++)
		up << (char)std::toupper(in.at(i));
	return up.str();
}
