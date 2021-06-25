/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 12:16:42 by fde-capu          #+#    #+#             */
/*   Updated: 2021/06/10 21:53:23 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

bool is_printable(char c)
{
	return c >= ' ' && c <= '~' ? 1: 0; // Considering <Space> is displayable.
}

template<typename T, typename A>
bool is_impossible(T checker, A against)
{
	(void)against;
	return checker != 0 && (checker != checker
	|| checker < std::numeric_limits<A>::min() 
	|| checker > std::numeric_limits<A>::max()) ? 1 : 0;
}

template<typename T>
void cout_cast(T checker)
{
	char cast_char = static_cast<char>(checker);
	int cast_int = static_cast<int>(checker);
	float cast_float = static_cast<float>(checker);
	double cast_double = static_cast<double>(checker);

	if (is_printable(cast_char))
		std::cout << "char: \'" << cast_char << "\'" << std::endl;
	else if (is_impossible(checker, cast_char))
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: non displayable" << std::endl;
	if (is_impossible(checker, cast_int))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << cast_int << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(PRECISION)
		<< cast_float << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(PRECISION)
		<< cast_double << std::endl;
	return ;
}

LiteralInRightType string_to_right_type(std::string str)
{
	// Your program must detect the literal’s type,
	// acquire that literal in the right type (so
	// it’s not a string anymore).
	LiteralInRightType l;
	switch (get_literal_type(str))
	{
		case TYPE_CHAR:
			l.c = str.at(0);
			break;
		case TYPE_INT:
			l.i = std::atoi(str.c_str());
			break;
		case TYPE_FLOAT:
			// std::atof returns a double (!)
			l.f = static_cast<float>(std::atof(str.c_str()));
			break;
		case TYPE_DOUBLE:
			l.d = std::atof(str.c_str());
			break;
	}
	return l;
}

int main(const int argc, const char * argv[])
{
	if (!validate_args(argc, argv))
		return 1;
	int my_type = get_literal_type(argv[1]);
	plot_type(my_type); // Bonus.
	LiteralInRightType literal = string_to_right_type(argv[1]);
	switch (get_literal_type(argv[1]))
	{
		case TYPE_CHAR:
			cout_cast(literal.c);
			break;
		case TYPE_INT:
			cout_cast(literal.i);
			break;
		case TYPE_FLOAT:
			cout_cast(literal.f);
			break;
		case TYPE_DOUBLE:
			cout_cast(literal.d);
			break;
	}
	return 0;
}
