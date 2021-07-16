/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_validation.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 12:28:26 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/16 11:22:33 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

int validate_args(const int argc, const char ** argv)
{
	if (argc != 2)
		return log_ret("Bad argument count.", 0);
	if (!get_literal_type(argv[1]))
		return log_ret("Invalid input.\nLiteral must "
			"belong to one of the following a scalar types: "
			"char, int, float or double.", 0);
	return 1;
}

int is_literal_char(std::string str)
{
	return	str.length() == 1
		&&	str.at(0)	 >= ' '
		&&	str.at(0)	 <= '~'
			?
			1 : 0;
}

long ft_stol(std::string str)
{
	unsigned long h = str.at(0) == '-' || str.at(0) == '+' ? 1 : 0;
	long l = 0;
	unsigned long i = h;
	while (i < str.length())
	{
		l += str.at(i) - '0';
		l *= i + 1 < str.length() ? 10 : 1;
		i++;
	}
	l *= str.at(0) == '-' ? -1 : 1;
	return l;
}

int only_this_chars(std::string str, std::string set)
{
	unsigned long i_set;
	unsigned long i_str = 0;
	int ok = 0;
	while (i_str < str.length())
	{
		i_set = 0;
		ok = 0;
		while (i_set < set.length())
		{
			if (set.at(i_set) == str.at(i_str))
				ok = 1;
			i_set++;
		}
		if (!ok)
			return 0;
		i_str++;
	}
	return 1;
}

int is_literal_int(std::string str)
{
	if (!(only_this_chars(str.substr(
		str.at(0) == '+' || str.at(0) == '-' ? 1 : 0
		), "0123456789")))
		return 0;
	if (str == "+" || str == "-")
		return 0;
	long l = ft_stol(str);
	return	l >= std::numeric_limits<int>::min()
		&&	l <= std::numeric_limits<int>::max()
			?
			1 : 0;
	return 0;
}

int count_char_in_str(char c, std::string str)
{
	int count = str.at(0) == c ? 1 : 0;
	return	count +	(str.length() == 1 ? 0 : count_char_in_str(c, str.substr(1)));
}

int digit_before_and_after_dot(std::string str)
{
	unsigned long dot = str.find(".");
	if (dot == 0)
		return 0;
	if (str.at(dot - 1) < '0' || str.at(dot - 1) > '9')
		return 0;
	if (str.at(dot + 1) < '0' || str.at(dot + 1) > '9')
		return 0;
	return 1;
}

int is_literal_float(std::string str)
{
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return 1;
	if (str.at(str.length() - 1) != 'f')
		return 0;
	unsigned long h = str.at(0) == '-' || str.at(0) == '+' ? 1 : 0;
	if (!(only_this_chars(str.substr(h, str.length() - 1 - h), ".0123456789")))
		return 0;
	if (count_char_in_str('.', str) != 1)
		return 0;
	if (!(digit_before_and_after_dot(str)))
		return 0;
	return 1;
}

int is_special_double(std::string str)
{
	return (str == "-inf" || str == "+inf" || str == "nan") ? 1 : 0;
}

int is_literal_double(std::string str)
{
	if (is_special_double(str))
		return 1;
	unsigned long h = str.at(0) == '-' || str.at(0) == '+' ? 1 : 0;
	if (!(only_this_chars(str.substr(h, str.length() - h), ".0123456789")))
		return 0;
	if (count_char_in_str('.', str) != 1)
		return 0;
	if (!(digit_before_and_after_dot(str)))
		return 0;
	return 1;
}
