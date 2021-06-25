/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:17:14 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/27 08:32:02 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Crap.hpp"

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

std::string	crappy_itos_0to7(int i)
{
	if (i == 0)	return std::string("0");
	if (i == 1)	return std::string("1");
	if (i == 2)	return std::string("2");
	if (i == 3)	return std::string("3");
	if (i == 4)	return std::string("4");
	if (i == 5)	return std::string("5");
	if (i == 6)	return std::string("6");
	if (i == 7)	return std::string("7");
	return 0;
}
