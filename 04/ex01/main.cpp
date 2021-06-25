/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:55:48 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/19 14:55:48 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "AWeapon.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "Enemy.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include "Character.hpp"

int main(void)
{
	{
		std::cout << std::endl << "SUBJECT SECTION" << std::endl;
		Character* me = new Character("me");
		std::cout << *me << std::endl;
		Enemy* b = new RadScorpion();
		AWeapon* pr = new PlasmaRifle();
		AWeapon* pf = new PowerFist();
		me->equip(pr);
		std::cout << *me << std::endl;
		me->equip(pf);
		me->attack(b);
		std::cout << *me << std::endl;
		me->equip(pr);
		std::cout << *me << std::endl;
		me->attack(b);
		std::cout << *me << std::endl;
		me->attack(b);
		std::cout << *me << std::endl;
		// THIS PART IS MISSING FROM THE SUBJECT:
		// DELETING THE ELEMENTS TO AVOID LEAK
		delete me;
		delete pr;
		delete pf;
		// We can not `delete b` because it is already dead,
		// and it is said to be deleted when dies,
		// which I think is not that good of a behavior.
	}
	{
		std::cout << std::endl << "FREE SECTION" << std::endl;

		std::cout << ":" << std::endl;
		Character* guy = new Character("A guy");
		std::cout << *guy << std::endl;
		Enemy* scorp = new RadScorpion();
		std::cout << *scorp << std::endl;
		Character guy2 = *guy; // Character::operator =
		std::cout << "[Guy copy] " << guy2 << std::endl;
		guy2.attack(scorp); // Does nothing, guy2 is unnarmed.
		AWeapon* plasma = new PlasmaRifle();
		std::cout << *plasma << std::endl;
		guy2.equip(plasma);
		std::cout << "[Guy copy] " << guy2 << *guy << std::endl; // Only the copy is armed.
		guy2.attack(scorp);
		std::cout << "[Guy cp] " << guy2 << *scorp << *guy << std::endl; // Only the copy looses AP, scorp looses HP.
		guy->attack(scorp); // does nothing (unnarmed)
		AWeapon* fist = new PowerFist();
		guy->equip(fist);
		std::cout << *guy << "[guy cp]" << guy2 << std::endl;
		guy->attack(scorp);
		std::cout << *scorp << *guy << "[guycp] " << guy2 << std::endl;
		// guy2 is not a pointer, it does not need deleteion.
		guy->attack(scorp); // scorp dies.
		//guy->attack(scorp); // this is invalid (scorp has been deleted)
		std::cout << *guy << std::endl;
		guy->recoverAP();
		std::cout << *guy << std::endl;
		guy->recoverAP();
		std::cout << *guy << std::endl; // No more than 40.
		guy->equip(0); // This may be called to unequip a weapon.
		std::cout << *guy << std::endl;
		guy->equip(plasma);
		std::cout << *guy << std::endl;
		Enemy* mutant = new SuperMutant();
		std::cout << *mutant << std::endl;
		guy->attack(mutant);
		std::cout << *mutant << std::endl; // Plama damage is 21, but SuperMutants get -3, so it is 18.
		std::cout << *guy << std::endl;
		guy->attack(mutant);
		guy->attack(mutant);
		guy->attack(mutant);
		guy->attack(mutant);
		guy->attack(mutant);
		guy->attack(mutant);
		guy->attack(mutant);
		std::cout << *guy << std::endl; // guy is out of AP
		std::cout << *mutant << std::endl;
		guy->attack(mutant); // nothing happens (no AP, and AP stay 0)
		guy->recoverAP();
		std::cout << *guy << std::endl; // now has 10
		guy->attack(mutant); // and can attack again
		std::cout << *mutant << std::endl; // mutant is 8 HP, will die
		guy->attack(mutant); // on this attack
		guy->attack(mutant); // This IS valid, because there is no AP anyway.
		guy->recoverAP();
		std::cout << *guy << std::endl;
		guy->equip(fist);
		std::cout << *guy << std::endl;
		//guy->attack(mutant); // This is invalid (mutant is deleted).
		mutant = new SuperMutant();
		std::cout << *mutant << std::endl;
		guy->attack(mutant);
		std::cout << *mutant << std::endl;
		std::cout << *guy << std::endl; // Guy has 2 AP
		guy->attack(mutant); // so no attack happens (not enough AP)
		std::cout << *mutant << std::endl; // enemy does not loose HP
		Enemy mutant2 = *mutant;
		std::cout << mutant2 << std::endl; // mutant2 initiate with mutant HP (123)
		guy->recoverAP();
		guy->attack(&mutant2);
		std::cout << mutant2 << std::endl;
		std::cout << *mutant << std::endl; // Only mutant2 has lost HP
		// mutant2 does not need deletion.
		delete plasma;
		delete fist;
		delete mutant;
		delete guy;
	}
	return 0;
}
