/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 12:29:06 by fde-capu          #+#    #+#             */
/*   Updated: 2021/06/10 13:58:42 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_HPP
# define HEADER_HPP
# include <string>
# include <limits>
# include "ft_cpp.hpp"
# include <iostream>
# include <cstdlib>
# include <sstream>
# include <iomanip>

# define TYPE_CHAR		1
# define TYPE_INT		2
# define TYPE_FLOAT		3
# define TYPE_DOUBLE	4
# define PRECISION		1

union LiteralInRightType
{
	char c;
	int i;
	float f;
	double d;
};

int get_literal_type(std::string str);
int validate_args(const int argc, const char ** argv);
int is_literal_char(std::string);
int is_literal_int(std::string);
int is_literal_float(std::string);
int is_special_double(std::string);
int is_literal_double(std::string);
void plot_type(int t);

#endif
