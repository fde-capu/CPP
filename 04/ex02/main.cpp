/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:56:12 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/13 18:08:38 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ISquad.hpp"
#include "Squad.hpp"
#include "ISpaceMarine.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"

int main()
{
	std::cout << "GIVEN MAIN" << std::endl;
	{
		ISpaceMarine* bob = new TacticalMarine;
		ISpaceMarine* jim = new AssaultTerminator;
		ISquad* vlc = new Squad;
		vlc->push(bob);
		vlc->push(jim);
		for (int i = 0; i < vlc->getCount(); ++i)
		{
			ISpaceMarine* cur = vlc->getUnit(i);
			cur->battleCry();
			cur->rangedAttack();
			cur->meleeAttack();
		}
		delete vlc;
	}
	std::cout << std::endl << "FREE MAIN" << std::endl;
	{
		Squad	squad;
		AssaultTerminator * at = new AssaultTerminator;
		squad.push(at);
		TacticalMarine  * tm = new TacticalMarine;
		squad.push(tm);
		Squad	squad_cp;
		squad_cp = squad; // This creates two new marines for the copy. True:
		std::cout << "(A) " << squad.getCount() << " == " << squad_cp.getCount() << std::endl;
		TacticalMarine * foo = new TacticalMarine;
		squad_cp.push(foo);
		std::cout << "(B) " << squad.getCount() << " =! " << squad_cp.getCount() << std::endl;
		squad.push(at); // Does nothing when pushing an already present unit.
		std::cout << "(C) " << squad.getCount() << " == 2" << std::endl;
		squad.push(0); // Does nothing when pushing null pointer.
		std::cout << "(D) " << squad.getCount() << " == 2" << std::endl;
		squad_cp = squad; // at2, tm2 and foo will die, two new copies of at and tm will be in squad_cp.
		std::cout << "(E) " << squad.getCount() << " == " << squad_cp.getCount() << std::endl;
		Squad hard_cp(squad); // Copy constructor
		std::cout << "(F) " << squad.getCount() << " == " << hard_cp.getCount() << std::endl;
		TacticalMarine * foo2 = new TacticalMarine;
		hard_cp.push(foo2);
		std::cout << "(G) " << squad.getCount() << " =! " << hard_cp.getCount() << std::endl;
		squad.getUnit(0)->battleCry(); // getUnit demo. This is AssaultTerminator, so "PURIFY"
		squad.getUnit(1)->battleCry(); // this is TacticalMarine, "PLOT"
		// Example above also proves that push puts new element at the end of line.
		squad.getUnit(-1); squad.getUnit(999); // Those are valid and return null pointer
		// squad.getUnit(-1)->battleCry(); // So this is invalid (segfault).
		//
		// Pushing a marine to a squad make it "compromissed", therefore can not
		// be pushed into other squad. (A deep copy is made and original freed.)
		//
		// Dying sequence is reverse, but marines in order for each squad.
		// This also shows squads are in correct order (pushed to end of line).
		std::cout << std::endl << "Deaths:" << std::endl;
	}
	return 0;
}
