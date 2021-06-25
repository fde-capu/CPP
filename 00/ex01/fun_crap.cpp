/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_crap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 07:24:36 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/15 00:22:46 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Crap.hpp"
#include <string>
#include <iostream>

Crap::Crap(void)
{
	*first_name = 0;
	*last_name = 0;
	*nickname = 0;
	*login = 0;
	*postal_address = 0;
	*email_address = 0;
	*phone_number = 0;
	*birthday_date = 0;
	*favorite_meal = 0;
	*underwear_color = 0;
	*darkest_secret = 0;
}

void	Crap::digest(int idx)
{
	std::string idxstr(crappy_itos_0to7(idx));
	std::cout << format_search((char *)idxstr.c_str()) << "|" << format_search(first_name) << "|" << format_search(last_name) << "|" << format_search(nickname) << std::endl;
}

void	Crap::poop(void)
{
	std::cout << std::endl;
	std::cout << "     first name: " << first_name << std::endl;
	std::cout << "      last name: " << last_name << std::endl;
	std::cout << "       nickname: " << nickname << std::endl;
	std::cout << "          login: " << login << std::endl;
	std::cout << " postal address: " << postal_address << std::endl;
	std::cout << "  email address: " << email_address << std::endl;
	std::cout << "   phone number: " << phone_number << std::endl;
	std::cout << "  birthday date: " << birthday_date << std::endl;
	std::cout << "  favorite meal: " << favorite_meal << std::endl;
	std::cout << "underwear color: " << underwear_color << std::endl;
	std::cout << " darkest secret: " << darkest_secret << std::endl;
	std::cout << std::endl;
}
