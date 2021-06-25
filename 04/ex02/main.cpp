/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:56:12 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/19 14:56:12 by fde-capu         ###   ########.fr       */
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
		Squad	s;
		AssaultTerminator * at = new AssaultTerminator;
		s.push(at);
		TacticalMarine  * tm = new TacticalMarine;
		s.push(tm);
		Squad	assig_cp;
		assig_cp = s; // This creates two new marines for the copy. True:
		std::cout << "(A) " << s.getCount() << " == " << assig_cp.getCount() << std::endl;
		TacticalMarine * foo = new TacticalMarine;
		assig_cp.push(foo);
		std::cout << "(B) " << s.getCount() << " =! " << assig_cp.getCount() << std::endl;
		s.push(at); // Does nothing when pushing an already present unit.
		std::cout << "(C) " << s.getCount() << " == 2" << std::endl;
		s.push(0); // Does nothing when pushing null pointer.
		std::cout << "(D) " << s.getCount() << " == 2" << std::endl;
		assig_cp = s; // at2, tm2 and foo will die, two new copies of at and tm will be in assig_cp.
		std::cout << "(E) " << s.getCount() << " == " << assig_cp.getCount() << std::endl;
		Squad hard_cp(s); // Copy constructor
		std::cout << "(F) " << s.getCount() << " == " << hard_cp.getCount() << std::endl;
		TacticalMarine * foo2 = new TacticalMarine;
		hard_cp.push(foo2);
		std::cout << "(G) " << s.getCount() << " =! " << hard_cp.getCount() << std::endl;
		s.getUnit(0)->battleCry(); // getUnit demo. This is AssaultTerminator, so "PURIFY"
		s.getUnit(1)->battleCry(); // this is TacticalMarine, "PLOT"
		// Example above also proves that push puts new element at the end of line.
		s.getUnit(-1); s.getUnit(999); // Those are valid and return null pointer
		// s.getUnit(-1)->battleCry(); // So this is invalid (segfault).
		//
		// Since copies are made hard, after pushing a marine to a squad,
		// it get "compromissed", therefore can not be pushed into other squad.
		//
		// Dying sequence is reverse, but marines in order for each squad.
		// This also shows squads are in correct order (pushed to end of line).
		std::cout << std::endl << "Deaths:" << std::endl;
	}
	return 0;
}
