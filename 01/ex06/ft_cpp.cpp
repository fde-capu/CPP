/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpp.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:44:06 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/14 23:50:13 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <iostream>

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
	{
		up << (char)toupper(in.at(i));
	}
	return up.str();
}
