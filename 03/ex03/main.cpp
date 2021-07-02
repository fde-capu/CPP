/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:13:24 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/01 13:37:42 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
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
		clappy.beRepaired(2); // energy_points AND hit_points are repaired (like *old* CPP 03).
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



	std::cout << "--------" << std::endl << "ex01 :: all same tests (but more attack)" << std::endl << "--------" << std::endl;





	{
		ScavTrap unnamed; // Default constructor (unnamed) not asked, but ortodox.
		std::cout << unnamed << std::endl; // Bonus: operator<<
		ScavTrap scavvy("Scavvy");
		std::cout << scavvy << std::endl;
		{
			std::cout << "------ Copy constructor test:" << std::endl;
			ScavTrap scavcopy(scavvy);
			std::cout << scavcopy << std::endl;
		}
		{
			std::cout << "------ Assignment operator test:" << std::endl;
			ScavTrap scavcopy;
			scavcopy = scavvy;
			std::cout << scavcopy << std::endl;
		}
		std::cout << "------ Attack test:" << std::endl;
		scavvy.attack("someone");
		std::cout << scavvy << std::endl;
		{
			std::cout << " --- Attack until no more hit_points:" << std::endl;
			ScavTrap scavcopy(scavvy);
			scavcopy.attack("someONE");
			std::cout << scavcopy << std::endl;
			scavcopy.attack("someTWO");
			std::cout << scavcopy << std::endl;
			scavcopy.attack("someTHREE");
			std::cout << scavcopy << std::endl;
			scavcopy.attack("someFOUR");
			std::cout << scavcopy << std::endl;
			scavcopy.attack("someFIVE");
			std::cout << scavcopy << std::endl;
		}
		std::cout << "------ Take damage test:" << std::endl;
		scavvy.takeDamage(3);
		std::cout << scavvy << std::endl;
		{
			std::cout << "   --- Take damage out of bound test:" << std::endl;
			ScavTrap temp_scavvy(scavvy);
			temp_scavvy.takeDamage(150); // More than enough, hit_points is zero (takes max).
			std::cout << temp_scavvy << std::endl;
			// temp_scavvy.takeDamage(-15); // Would implicit cast signed to unsigned (a mess).
			// ...but compilation fails, since using -Wconversion.
		}
		{
			std::cout << "------ Again, copy constructor test (check life values):" << std::endl;
			ScavTrap scavcopy(scavvy);
			std::cout << scavcopy << std::endl;
		}
		{
			std::cout << "------ Again, assignment operator test (check life values):" << std::endl;
			ScavTrap scavcopy;
			scavcopy = scavvy;
			std::cout << scavcopy << std::endl;
		}
		std::cout << "------ beRepaired() test:" << std::endl;
		std::cout << scavvy << std::endl;
		scavvy.beRepaired(2); // energy_points AND hit_points are repaired (like *old* CPP 03).
		// scavvy.beRepaired(-10); // Prevented by -Wconversion.
		std::cout << scavvy << std::endl;
		{
			std::cout << "------ Copy is not another reference (one does not affect other):" << std::endl;
			ScavTrap temp_scavvy(scavvy);
			ScavTrap scavcopy(temp_scavvy);
			std::cout << " -- energy_points -- scavvy: " << temp_scavvy.getEnergyPoints() << " -- scavcopy: " << scavcopy.getEnergyPoints() << std::endl;
			temp_scavvy.takeDamage(3);
			std::cout << " -- energy_points -- scavvy: " << temp_scavvy.getEnergyPoints() << " -- scavcopy: " << scavcopy.getEnergyPoints() << std::endl;
			scavcopy.takeDamage(5);
			std::cout << " -- energy_points -- scavvy: " << temp_scavvy.getEnergyPoints() << " -- scavcopy: " << scavcopy.getEnergyPoints() << std::endl;
			temp_scavvy.beRepaired(7);
			std::cout << " -- energy_points -- scavvy: " << temp_scavvy.getEnergyPoints() << " -- scavcopy: " << scavcopy.getEnergyPoints() << std::endl;
			scavcopy.beRepaired(1);
			std::cout << " -- energy_points -- scavvy: " << temp_scavvy.getEnergyPoints() << " -- scavcopy: " << scavcopy.getEnergyPoints() << std::endl;
		}
		{
			std::cout << "------ Assignment is not another reference (one does not affect other):" << std::endl;
			ScavTrap temp_scavvy(scavvy);
			ScavTrap scavcopy;
			scavcopy = temp_scavvy;
			std::cout << " -- energy_points -- scavvy: " << temp_scavvy.getEnergyPoints() << " -- scavcopy: " << scavcopy.getEnergyPoints() << std::endl;
			temp_scavvy.takeDamage(3);
			std::cout << " -- energy_points -- scavvy: " << temp_scavvy.getEnergyPoints() << " -- scavcopy: " << scavcopy.getEnergyPoints() << std::endl;
			scavcopy.takeDamage(5);
			std::cout << " -- energy_points -- scavvy: " << temp_scavvy.getEnergyPoints() << " -- scavcopy: " << scavcopy.getEnergyPoints() << std::endl;
			temp_scavvy.beRepaired(7);
			std::cout << " -- energy_points -- scavvy: " << temp_scavvy.getEnergyPoints() << " -- scavcopy: " << scavcopy.getEnergyPoints() << std::endl;
			scavcopy.beRepaired(1);
			std::cout << " -- energy_points -- scavvy: " << temp_scavvy.getEnergyPoints() << " -- scavcopy: " << scavcopy.getEnergyPoints() << std::endl;
		}
		{
			std::cout << "------ Test guardGate()" << std::endl;
			std::cout << scavvy << std::endl;
			scavvy.guardGate();
			std::cout << scavvy << std::endl;
			std::cout << " --- Does it copy gate_keeper_mode?" << std::endl;
			ScavTrap scavcopy(scavvy);
			std::cout << scavcopy << std::endl;
			// No one asked for anything to get out of gate_keeper_mode.
		}
	}




	std::cout << "-------" << std::endl << "ex02" << std::endl << "--------" << std::endl;
	std::cout << "--- All tests once again..." << std::endl;
	
	
	
	{
		FragTrap unnamed; // Default constructor (unnamed) not asked, but ortodox.
		std::cout << unnamed << std::endl; // Bonus: operator<<
		FragTrap fraggy("Fraggy");
		std::cout << fraggy << std::endl;
		{
			std::cout << "------ Copy constructor test:" << std::endl;
			FragTrap froggy(fraggy);
			std::cout << froggy << std::endl;
		}
		{
			std::cout << "------ Assignment operator test:" << std::endl;
			FragTrap froggy;
			froggy = fraggy;
			std::cout << froggy << std::endl;
		}
		std::cout << "------ Attack test:" << std::endl;
		fraggy.attack("someone");
		std::cout << fraggy << std::endl;
		{
			std::cout << " --- Attack until no more hit_points:" << std::endl;
			FragTrap froggy(fraggy);
			froggy.attack("someONE");
			std::cout << froggy << std::endl;
			froggy.attack("someTWO");
			std::cout << froggy << std::endl;
			froggy.attack("someTHREE");
			std::cout << froggy << std::endl;
			froggy.attack("someFOUR");
			std::cout << froggy << std::endl;
			froggy.attack("someFIVE");
			std::cout << froggy << std::endl;
		}
		std::cout << "------ Take damage test:" << std::endl;
		fraggy.takeDamage(3);
		std::cout << fraggy << std::endl;
		{
			std::cout << "   --- Take damage out of bound test:" << std::endl;
			FragTrap temp_fraggy(fraggy);
			temp_fraggy.takeDamage(150); // More than enough, hit_points is zero (takes max).
			std::cout << temp_fraggy << std::endl;
			// temp_fraggy.takeDamage(-15); // Would implicit cast signed to unsigned (a mess).
			// ...but compilation fails, since using -Wconversion.
		}
		{
			std::cout << "------ Again, copy constructor test (check life values):" << std::endl;
			FragTrap froggy(fraggy);
			std::cout << froggy << std::endl;
		}
		{
			std::cout << "------ Again, assignment operator test (check life values):" << std::endl;
			FragTrap froggy;
			froggy = fraggy;
			std::cout << froggy << std::endl;
		}
		std::cout << "------ beRepaired() test:" << std::endl;
		std::cout << fraggy << std::endl;
		fraggy.beRepaired(2); // energy_points AND hit_points are repaired (like *old* CPP 03).
		// fraggy.beRepaired(-10); // Prevented by -Wconversion.
		std::cout << fraggy << std::endl;
		{
			std::cout << "------ Copy is not another reference (one does not affect other):" << std::endl;
			FragTrap temp_fraggy(fraggy);
			FragTrap froggy(temp_fraggy);
			std::cout << " -- energy_points -- fraggy: " << temp_fraggy.getEnergyPoints() << " -- froggy: " << froggy.getEnergyPoints() << std::endl;
			temp_fraggy.takeDamage(3);
			std::cout << " -- energy_points -- fraggy: " << temp_fraggy.getEnergyPoints() << " -- froggy: " << froggy.getEnergyPoints() << std::endl;
			froggy.takeDamage(5);
			std::cout << " -- energy_points -- fraggy: " << temp_fraggy.getEnergyPoints() << " -- froggy: " << froggy.getEnergyPoints() << std::endl;
			temp_fraggy.beRepaired(7);
			std::cout << " -- energy_points -- fraggy: " << temp_fraggy.getEnergyPoints() << " -- froggy: " << froggy.getEnergyPoints() << std::endl;
			froggy.beRepaired(1);
			std::cout << " -- energy_points -- fraggy: " << temp_fraggy.getEnergyPoints() << " -- froggy: " << froggy.getEnergyPoints() << std::endl;
		}
		{
			std::cout << "------ Assignment is not another reference (one does not affect other):" << std::endl;
			FragTrap temp_fraggy(fraggy);
			FragTrap froggy;
			froggy = temp_fraggy;
			std::cout << " -- energy_points -- fraggy: " << temp_fraggy.getEnergyPoints() << " -- froggy: " << froggy.getEnergyPoints() << std::endl;
			temp_fraggy.takeDamage(3);
			std::cout << " -- energy_points -- fraggy: " << temp_fraggy.getEnergyPoints() << " -- froggy: " << froggy.getEnergyPoints() << std::endl;
			froggy.takeDamage(5);
			std::cout << " -- energy_points -- fraggy: " << temp_fraggy.getEnergyPoints() << " -- froggy: " << froggy.getEnergyPoints() << std::endl;
			temp_fraggy.beRepaired(7);
			std::cout << " -- energy_points -- fraggy: " << temp_fraggy.getEnergyPoints() << " -- froggy: " << froggy.getEnergyPoints() << std::endl;
			froggy.beRepaired(1);
			std::cout << " -- energy_points -- fraggy: " << temp_fraggy.getEnergyPoints() << " -- froggy: " << froggy.getEnergyPoints() << std::endl;
		}
		{
			std::cout << " --- Test highFiveGuys():" << std::endl;
			fraggy.highFiveGuys();
		}
	}






	std::cout << std::endl << "--------" << std::endl << "ex03" << std::endl << "--------" << std::endl;
	{
		std::cout << "---- Differential test:" << std::endl;
		DiamondTrap diamond("Diamonddy");
		std::cout << diamond << std::endl;
		diamond.whoAmI();
		diamond.attack("someone");
		diamond.highFiveGuys();
		diamond.guardGate();
		std::cout << diamond << std::endl;
	}
	std::cout << "---- All the same tests (again):" << std::endl;
	{
		DiamondTrap unnamed; // Default constructor (unnamed) not asked, but ortodox.
		std::cout << unnamed << std::endl; // Bonus: operator<<
		DiamondTrap diamonddy("Diamonddy");
		std::cout << diamonddy << std::endl;
		{
			std::cout << "------ Copy constructor test:" << std::endl;
			DiamondTrap diamcopy(diamonddy);
			std::cout << diamcopy << std::endl;
		}
		{
			std::cout << "------ Assignment operator test:" << std::endl;
			DiamondTrap diamcopy;
			diamcopy = diamonddy;
			std::cout << diamcopy << std::endl;
		}
		std::cout << "------ Attack test:" << std::endl;
		diamonddy.attack("someone");
		std::cout << diamonddy<< std::endl;
		{
			std::cout << " --- Attack until no more hit_points:" << std::endl;
			DiamondTrap diamcopy(diamonddy);
			diamcopy.attack("someONE");
			std::cout << diamcopy << std::endl;
			diamcopy.attack("someTWO");
			std::cout << diamcopy << std::endl;
			diamcopy.attack("someTHREE");
			std::cout << diamcopy << std::endl;
			diamcopy.attack("someFOUR");
			std::cout << diamcopy << std::endl;
			diamcopy.attack("someFIVE");
			std::cout << diamcopy << std::endl;
		}
		std::cout << "------ Take damage test:" << std::endl;
		diamonddy.takeDamage(3);
		std::cout << diamonddy<< std::endl;
		{
			std::cout << "   --- Take damage out of bound test:" << std::endl;
			DiamondTrap temp_diamonddy(diamonddy);
			temp_diamonddy.takeDamage(150); // More than enough, hit_points is zero (takes max).
			std::cout << temp_diamonddy << std::endl;
			// temp_diamonddy.takeDamage(-15); // Would implicit cast signed to unsigned (a mess).
			// ...but compilation fails, since using -Wconversion.
		}
		{
			std::cout << "------ Again, copy constructor test (check life values):" << std::endl;
			DiamondTrap diamcopy(diamonddy);
			std::cout << diamcopy << std::endl;
		}
		{
			std::cout << "------ Again, assignment operator test (check life values):" << std::endl;
			DiamondTrap diamcopy;
			diamcopy = diamonddy;
			std::cout << diamcopy << std::endl;
		}
		std::cout << "------ beRepaired() test:" << std::endl;
		std::cout << diamonddy << std::endl;
		diamonddy.beRepaired(2); // energy_points AND hit_points are repaired (like *old* CPP 03).
		// diamonddy.beRepaired(-10); // Prevented by -Wconversion.
		std::cout << diamonddy << std::endl;
		{
			std::cout << "------ Copy is not another reference (one does not affect other):" << std::endl;
			DiamondTrap temp_diamonddy(diamonddy);
			DiamondTrap diamcopy(temp_diamonddy);
			std::cout << " -- energy_points -- diamonddy: " << temp_diamonddy.getEnergyPoints() << " -- diamcopy: " << diamcopy.getEnergyPoints() << std::endl;
			temp_diamonddy.takeDamage(3);
			std::cout << " -- energy_points -- diamonddy: " << temp_diamonddy.getEnergyPoints() << " -- diamcopy: " << diamcopy.getEnergyPoints() << std::endl;
			diamcopy.takeDamage(5);
			std::cout << " -- energy_points -- diamonddy: " << temp_diamonddy.getEnergyPoints() << " -- diamcopy: " << diamcopy.getEnergyPoints() << std::endl;
			temp_diamonddy.beRepaired(7);
			std::cout << " -- energy_points -- diamonddy: " << temp_diamonddy.getEnergyPoints() << " -- diamcopy: " << diamcopy.getEnergyPoints() << std::endl;
			diamcopy.beRepaired(1);
			std::cout << " -- energy_points -- diamonddy: " << temp_diamonddy.getEnergyPoints() << " -- diamcopy: " << diamcopy.getEnergyPoints() << std::endl;
		}
		{
			std::cout << "------ Assignment is not another reference (one does not affect other):" << std::endl;
			DiamondTrap temp_diamonddy(diamonddy);
			DiamondTrap diamcopy;
			diamcopy = temp_diamonddy;
			std::cout << " -- energy_points -- diamonddy: " << temp_diamonddy.getEnergyPoints() << " -- diamcopy: " << diamcopy.getEnergyPoints() << std::endl;
			temp_diamonddy.takeDamage(3);
			std::cout << " -- energy_points -- diamonddy: " << temp_diamonddy.getEnergyPoints() << " -- diamcopy: " << diamcopy.getEnergyPoints() << std::endl;
			diamcopy.takeDamage(5);
			std::cout << " -- energy_points -- diamonddy: " << temp_diamonddy.getEnergyPoints() << " -- diamcopy: " << diamcopy.getEnergyPoints() << std::endl;
			temp_diamonddy.beRepaired(7);
			std::cout << " -- energy_points -- diamonddy: " << temp_diamonddy.getEnergyPoints() << " -- diamcopy: " << diamcopy.getEnergyPoints() << std::endl;
			diamcopy.beRepaired(1);
			std::cout << " -- energy_points -- diamonddy: " << temp_diamonddy.getEnergyPoints() << " -- diamcopy: " << diamcopy.getEnergyPoints() << std::endl;
		}
		{
			std::cout << " --- Test highFiveGuys():" << std::endl;
			diamonddy.highFiveGuys();
		}
	}
}
