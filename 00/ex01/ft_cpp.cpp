/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpp.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:44:06 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/15 00:16:32 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Crap.hpp"
#include <cstdlib> // atoi;

int		prompt_str(const char *txt, std::string *com)
{
	std::cout << txt << std::endl;
	std::cin.clear();
	getline(std::cin, *com);
	if (std::cin.eof() == 1) // Bonus: Ctrl-D quits gracefully.
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout << std::endl;
		return 0;
	}
	return 1;
}

int		prompt_int(const char *txt, int *num)
{
	std::cout << txt << std::endl;
	std::cin.clear();
	std::string	com;
	getline(std::cin, com);
	if (std::cin.eof() == 1) // Bonus: Ctrl-D quits gracefully.
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout << std::endl;
		return 0;
	}
	if (ft_isnumber(com.c_str()))
	{
		*num = std::atoi(com.c_str());
		if (!num)
			return 0;
		return 1;
	}
	return 0;
}

int		prompt_range(const char *txt, int *num, int min, int max)
{
	int	t;

	t = 0;
	if (!(prompt_int(txt, &t)))
		return 0;
	if (t < min || t > max)
		return 0;
	*num = t;
	return 1;
}
