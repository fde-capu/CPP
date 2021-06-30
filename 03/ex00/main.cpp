/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 10:59:20 by fde-capu          #+#    #+#             */
/*   Updated: 2021/06/30 12:01:02 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap unnamed; // Default constructor (unnamed) not asked, but ortodox.
	std::cout << unnamed << std::endl; // Bonus: operator<<
	ClapTrap clappy("Clappy");
	std::cout << clappy << std::endl;
	{
		std::cout << "------ Copy constructor test:" << std::endl;
		ClapTrap cloppy(clappy);
		std::cout << cloppy << std::endl;
	}
	{
		std::cout << "------ Assignment operator test:" << std::endl;
		ClapTrap cloppy;
		cloppy = clappy;
		std::cout << cloppy << std::endl;
	}
	std::cout << "------ Attack test:" << std::endl;
	clappy.attack("someone");
	std::cout << clappy << std::endl; // attack_damage is 0 so no hit_points reduction.
	std::cout << "------ Take damage test:" << std::endl;
	clappy.takeDamage(3);
	std::cout << clappy << std::endl;
	{
		std::cout << "   --- Take damage out of bound test:" << std::endl;
		ClapTrap temp_clappy(clappy);
		temp_clappy.takeDamage(15); // More than enough, hit_points is zero (takes max).
		std::cout << temp_clappy << std::endl;
		// temp_clappy.takeDamage(-15); // Would implicit cast signed to unsigned (a mess).
		// ...but compilation fails, since using -Wconversion.
	}
	{
		std::cout << "------ Again, copy constructor test (check life values):" << std::endl;
		ClapTrap cloppy(clappy);
		std::cout << cloppy << std::endl;
	}
	{
		std::cout << "------ Again, assignment operator test (check life values):" << std::endl;
		ClapTrap cloppy;
		cloppy = clappy;
		std::cout << cloppy << std::endl;
	}
	std::cout << "------ beRepaired() test:" << std::endl;
	std::cout << clappy << std::endl;
	clappy.beRepaired(2); // energy_points AND hit_points are repaired (like old CPP 03).
	// clappy.beRepaired(-10); // Prevented by -Wconversion.
	std::cout << clappy << std::endl;
	{
		std::cout << "------ Copy is not another reference (one does not affect other):" << std::endl;
		ClapTrap temp_clappy(clappy);
		ClapTrap cloppy(temp_clappy);
		std::cout << " -- energy_points -- clappy: " << temp_clappy.getEnergyPoints() << " -- cloppy: " << cloppy.getEnergyPoints() << std::endl;
		temp_clappy.takeDamage(3);
		std::cout << " -- energy_points -- clappy: " << temp_clappy.getEnergyPoints() << " -- cloppy: " << cloppy.getEnergyPoints() << std::endl;
		cloppy.takeDamage(5);
		std::cout << " -- energy_points -- clappy: " << temp_clappy.getEnergyPoints() << " -- cloppy: " << cloppy.getEnergyPoints() << std::endl;
		temp_clappy.beRepaired(7);
		std::cout << " -- energy_points -- clappy: " << temp_clappy.getEnergyPoints() << " -- cloppy: " << cloppy.getEnergyPoints() << std::endl;
		cloppy.beRepaired(1);
		std::cout << " -- energy_points -- clappy: " << temp_clappy.getEnergyPoints() << " -- cloppy: " << cloppy.getEnergyPoints() << std::endl;
	}
	{
		std::cout << "------ Assignment is not another reference (one does not affect other):" << std::endl;
		ClapTrap temp_clappy(clappy);
		ClapTrap cloppy;
		cloppy = temp_clappy;
		std::cout << " -- energy_points -- clappy: " << temp_clappy.getEnergyPoints() << " -- cloppy: " << cloppy.getEnergyPoints() << std::endl;
		temp_clappy.takeDamage(3);
		std::cout << " -- energy_points -- clappy: " << temp_clappy.getEnergyPoints() << " -- cloppy: " << cloppy.getEnergyPoints() << std::endl;
		cloppy.takeDamage(5);
		std::cout << " -- energy_points -- clappy: " << temp_clappy.getEnergyPoints() << " -- cloppy: " << cloppy.getEnergyPoints() << std::endl;
		temp_clappy.beRepaired(7);
		std::cout << " -- energy_points -- clappy: " << temp_clappy.getEnergyPoints() << " -- cloppy: " << cloppy.getEnergyPoints() << std::endl;
		cloppy.beRepaired(1);
		std::cout << " -- energy_points -- clappy: " << temp_clappy.getEnergyPoints() << " -- cloppy: " << cloppy.getEnergyPoints() << std::endl;
	}
}
