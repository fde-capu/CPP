/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:55:05 by fde-capu          #+#    #+#             */
/*   Updated: 2021/06/02 12:43:02 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"
#include <iostream>
#include <cstdlib>

void	randomChump(void)
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
	const std::string	rnd_name = names[rand() % 101];
	Zombie	z(rnd_name);
	z.announce();
	return ;
}

int	main(void)
{
	ZombieEvent	ze;
	Zombie*		z[9];
	int			i;

	std::cout << std::endl << "// First, create some zombies with no type" << std::endl;
	std::cout << "// \"The Generic Zombie\" default type for ZombieEvent creation." << std::endl;
	z[0] = ze.newZombie("Sophia Peletier");
	z[1] = ze.newZombie("Azrail");
	z[2] = ze.newZombie("Dabria");

	std::cout << std::endl << "// Then, after calling the function setZombieType()," << std::endl;
	std::cout << "// ...all newly created zombies will be of that type." << std::endl;
	ze.setZombieType("Sankarea");
	z[3] = ze.newZombie("Sue Dibney");
	z[4] = ze.newZombie("Amy");
	z[5] = ze.newZombie("Cassidy");

	std::cout << std::endl << "// Again, for demonstration effect:" << std::endl;
	ze.setZombieType("The Crazies");
	z[6] = ze.newZombie("Amara");
	z[7] = ze.newZombie("Jiangshi");
	z[8] = ze.newZombie("Morty");

	std::cout << std::endl << "// All those above are heap allocated zombies." << std::endl;
	std::cout << "// They are manually cleared." << std::endl;

	for (i = 0; i <= 8; i++)
	{
		if (z[i])
			delete z[i];
	}

	std::cout << std::endl << "// And now some random names." << std::endl;
	std::cout << "// Those are stack allocated inside randomChump()." << std::endl;
	srand((unsigned int)time(NULL));
	randomChump();
	randomChump();
	randomChump();
	randomChump();
	randomChump();
	randomChump();
	randomChump();
	randomChump();
	randomChump();
	randomChump();
	randomChump();
	std::cout << std::endl;

	return 0;
}
