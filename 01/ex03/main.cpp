/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:55:05 by fde-capu          #+#    #+#             */
/*   Updated: 2021/06/02 12:44:35 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieHorde.hpp"
#include <iostream>
#include <cstdlib>

std::string	random_name(void)
{
	const std::string	names[101] = {"Ash Williams", \
	"Billy Butcherson", \
	"Bub", "Dr. Hill", "Ed", "Detective Roger Mortis", "Eddie", \
	"Evil Ash", "Fido", "Frankenstein", "Ghoulia Yelps", \
	"Jason Todd", "Jason Voorhees", "Judge Hopkins", "Julie", \
	"Karen Cooper", "Liv Moore", "M", "Madeline Ashton", \
	"Merle Dixon", "Murphy", "Pete", "R", "Randall Skeffington", \
	"She", "Sheila Hammond", "Solomon Grundy", "Sophia Peletier", \
	"Tarman", "White Walker", "Albert Francis", "Boston Brand", \
	"Cassidy", "Deathlok", "Eric Draven", "Frank Castle", \
	"Hannibal King", "Jim Corrigan", "Jonathan Osterman", \
	"Mitchell Shelley", "Moonbeam", "Ralph Dibney", "Simon Dark", \
	"Simon William Garth", "Sue Dibney", "Abdulbaith", "Ajal", \
	"Amara", "Arius", "Azrail", "Dabria", "Dearil", "Javaraya", \
	"Kalabhiti", "Kalakuta", "Khalida", "Lorelai", "Mayhem", \
	"Morrigan", "Mirthunjayan", "Omisha", "Tuwile", "Thanatos", \
	"Yamajit", "Yamaraj", "Aeron", "Libitina", "Marduk", "Merikh", \
	"Mirrikh", "Morana", "Mortimer", "Mort", "Morty", "Than", \
	"Thana", "Thanatos", "Valdis", "Valadis", "Waldeburg", "Jiangshi", \
	"Amy", "Andrea", "Deanna Monroe", "Enid", "Ezekiel", \
	"Hershel Greene", "Jessie Anderson", "Merle Dixon", "Lori Grimes", \
	"Olivia", "Philip Blake", "Rosita Espinosa", "Sasha Williams", \
	"Shane Walsh", "Sophia Peletier", "Siddiq", "Simon", \
	"Spencer Monroe", "Tara Chambler", "Tyreese"};
	std::string	rnd_name = names[rand() % 101];
	const std::string out(rnd_name);
	return (out);
}

int	main(void)
{
	srand((unsigned int)time(NULL));
	ZombieHorde	h1(1); // Just a single test.
	h1.announce();
	ZombieHorde h2(10); // You can mess around any int.
	h2.announce();
	return 0;
}
