/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Crap.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 10:12:04 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/15 00:12:35 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Crap.hpp"
#include <iomanip>	// setw();
#include <sstream>
#include <iostream>

void	ask(std::string prompt, char *field)
{
	std::string	in;

	std::cin.clear();
	in = "";
	std::cout << prompt << std::endl;
	getline(std::cin, in);
	std::string str(in);
	if (str.length() > ENTRY_LIMIT)
	{
		std::cout << "Maximum " << ENTRY_LIMIT << " chars." << std::endl;
		return (ask(prompt, field));
	}
	std::size_t len = str.copy(field, ENTRY_LIMIT, 0);
	field[len] = 0;
	return ;
}

void	crappy_add(Crap *book)
{
	ask("first name: ",			book->first_name);
	ask("last name: ",			book->last_name);
	ask("nickname: ",			book->nickname);
	ask("login: ",				book->login);
	ask("postal address: ",		book->postal_address);
	ask("email address: ",		book->email_address);
	ask("phone number: ",		book->phone_number);
	ask("birthday date: ",		book->birthday_date);
	ask("favorite meal: ",		book->favorite_meal);
	ask("underwear color: ",	book->underwear_color);
	ask("darkest secret: ",		book->darkest_secret);
	return ;
}

void	crappy_search(Crap book[7], int max)
{
	int	idx;
	std::string	com;
	int	query;

	if (max < 0)
		return ;
	idx = -1;
	while (++idx <= max)
		book[idx].digest(idx);
	if (!(prompt_range("[index] ", &query, 0, max)))
		return ;
	book[query].poop();
	return ;
}


std::string	format_search(char *param)
{
	std::string	str(param);
	if (str.length() > 10)
	{
		str[9] = '.';
		str.resize(10);
		return (str);
	}
	if (str.length() == 10)
		return (str);
	std::stringstream out;
	out << std::right << std::setw(10) << str;
	return (out.str());
}

int	main(void)
{
	static int	idx = 0;
	Crap		book[BOOK_LIMIT];
	std::string	com;

	while (1)
	{
		if (!(prompt_str("[SEARCH|ADD|EXIT] ", &com)))
			break ;
		if (!com.compare("EXIT"))
			break ;
		if (!com.compare("SEARCH"))
			crappy_search(book, idx - 1);
		if (!com.compare("ADD") && idx < BOOK_LIMIT)
			crappy_add(&book[idx++]);
		if (!com.compare("ADD") && idx >= BOOK_LIMIT)
			std::cout << "Limit of " << BOOK_LIMIT << " entries reached.\n" << std::endl;
	}
	return 0;
}
