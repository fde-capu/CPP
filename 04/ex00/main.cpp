/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:55:02 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/19 14:55:02 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"

void	testSorcerer(void)
{
	std::cout << "--- Colpien test ---" << std::endl;
	std::cout << "Construct:" << std::endl;
	Sorcerer robert("Robert", "the Magnificent");
	{
		std::cout << "Copy must initialize the same, but may have differente values:" << std::endl;
		Sorcerer rob_cp = robert;
		std::cout << robert << rob_cp << std::endl;
		rob_cp.name = "RobertCopy";
		std::cout << robert << rob_cp << std::endl;
		std::cout << "Attribution:" << std::endl;
		Sorcerer rob_cp2(robert);
		std::cout << robert << rob_cp2 << std::endl;
		rob_cp2.name = "RobertCopyTwo";
		std::cout << robert << rob_cp2 << std::endl;
		std::cout << "Deconstruct 2 copy elements:" << std::endl;
	}
	std::cout << "--- end of Colpien test ---" << std::endl;
	std::cout << "Sorcerer::polymorph on Victim:" << std::endl;
	Victim jim("Jimmy");
	robert.polymorph(jim);
	return ;
}

void	testVictim(void)
{
	std::cout << "--- Colpien test ---" << std::endl;
	std::cout << "Construct:" << std::endl;
	Victim victim("Jimmy");
	{
		std::cout << "Copy must initialize the same, but may have differente values:" << std::endl;
		Victim vic_cp = victim;
		std::cout << victim << vic_cp << std::endl;
		vic_cp.name = "JimmyCopy";
		std::cout << victim << vic_cp << std::endl;
		std::cout << "Attribution:" << std::endl;
		Victim vic_cp2(victim);
		std::cout << victim << vic_cp2 << std::endl;
		vic_cp2.name = "JimmyCopyTwo";
		std::cout << victim << vic_cp2 << std::endl;
		std::cout << "Deconstruct 2 copy elements:" << std::endl;
	}
	std::cout << "--- end of Colpien test ---" << std::endl;
	std::cout << "Victim::getPolymorphed:" << std::endl;
	victim.getPolymorphed();
	return ;
}

void	testPeon(void)
{
	std::cout << "--- Colpien test ---" << std::endl;
	std::cout << "Construct:" << std::endl;
	Peon peon("Joe");
	{
		std::cout << "Copy:" << std::endl;
		Peon peon_cp = peon;
		std::cout << peon << peon_cp << std::endl;
		peon_cp.name = "JoeCopy";
		std::cout << peon << peon_cp << std::endl;
		std::cout << "Attribution:" << std::endl;
		Peon peon_cp2(peon);
		std::cout << peon << peon_cp2 << std::endl;
		peon_cp2.name = "JoeCopyTwo";
		std::cout << peon << peon_cp2 << std::endl;
		std::cout << "Deconstruct 2 copy elements:" << std::endl;
	}
	std::cout << "--- end of Colpien test ---" << std::endl;
	std::cout << "Peon::getPolymorphed:" << std::endl;
	peon.getPolymorphed();
	return ;
}

int	main(void)
{
	testSorcerer();
	testVictim();
	testPeon();
	std::cout << std::endl << "--- Now the subject main ---" << std::endl << std::endl;
	{
		Sorcerer robert("Robert", "the Magnificent");
		Victim jim("Jimmy");
		Peon joe("Joe");
		std::cout << robert << jim << joe << std::endl;
		robert.polymorph(jim);
		robert.polymorph(joe);
		return 0;
	}
}
