/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:56:22 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/19 14:56:22 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
	std::cout << "Given main" << std::endl << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}
	std::cout << std::endl;
	std::cout << "Demo functionalities" << std::endl << std::endl;
	{
		MateriaSource * src = new MateriaSource();
		std::cout << "A " << *src << std::endl;
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		std::cout << "B " << *src << std::endl;
		src->learnMateria(new Ice()); // Valid: learnMateria is not
		// necessarily unique.
		std::cout << "C " << *src << std::endl;
		src->learnMateria(new Cure()); // Takes a maximum of four learnings,
		std::cout << "D " << *src << std::endl;
		// The subject underlies same material learning has the only
		// practical effect of taking a learning slot.
		src->learnMateria(new Ice()); // This does nothing, slots are full.
		// In this case, (bonus) the "new Ice()" gets deleted (no leaks).
		std::cout << "E " << *src << std::endl;
		{
			MateriaSource src_cp = *src; // Deep copy of MateriaSource
			// (bonus).
			std::cout << "F " << src_cp << std::endl;
		}
		{
			MateriaSource src_cp = MateriaSource(*src); // Reference
			// constructor (also deep), bonus.
			std::cout << "G " << src_cp << std::endl;
		}
		Character * me = new Character("TheCharacter");
		std::cout << "H " << *me << std::endl;
		AMateria * tmp;
		tmp = src->createMateria("foo"); // Materia gets rejected
		// (not learned, nothing done).
		tmp = src->createMateria("ice");
		std::cout << "I " << *tmp << "\t" << tmp << std::endl;
		me->equip(tmp);
		std::cout << "J " << *me << std::endl;
		me->equip(tmp); // Bonus. Does nothing when equipping the same
		// equip.
		std::cout << "K " << *me << std::endl;
		tmp = src->createMateria("cure");
		std::cout << "L " << *tmp << "\t" << tmp << std::endl;
		me->equip(tmp);
		std::cout << "M " << *me << std::endl;
		Character * bob = new Character("Bob");
		std::cout << "N " << *bob << std::endl;
		me->use(1, *bob);
		std::cout << "O " << *me << std::endl; // XP has increased
		std::cout << "P " << *src << std::endl; // source XP is always
		// 0 (learned but not created materia).
		tmp = src->createMateria("cure");
		bob->equip(tmp); // New equip, mew naterial copy, own XP
		std::cout << "Q " << *bob << std::endl;
		bob->use(0, *me);
		bob->use(1, *me); // Does nothing (unequipped).
		bob->use(-6, *me); // Does nothing (invalid parameter).
		bob->use(42, *me); // Does nothing (invalid parameter).
		bob->use(0, *me);
		std::cout << "R " << *bob << *me << std::endl;
		{
			Character bobby = *bob; // Deep copy of Character.
			std::cout << "S " << bobby << std::endl;
			// Equipment is also duplicated, and their XP is
			// intentilnally reset to zero.
			bobby.use(0, *me);
			std::cout << "T " << bobby << *bob << std::endl;
			// Materials XP runs one for each (it is a copy alterall).
		}
		{
			Character bobby = Character(*bob); // By reference. Same
			// tests as above.
			std::cout << "U " << bobby << std::endl;
			bobby.use(0, *me);
			std::cout << "V " << bobby << *bob << std::endl;
		}
		tmp = src->createMateria("ice");
		me->equip(tmp); // It is another copy of cure. It still cannot
		// be equiped (by design), because of the same name.
		// At this point, if tmp is not freed or equipped, it will leak.
		// tmp = src->createMateria("cure"); // This would make the
		// above line to be leaked.
		bob->equip(tmp);
		std::cout << "W " << *bob << std::endl;
		bob->unequip(0);
		std::cout << "X " << *bob << std::endl; // Slot 0 is freed,
		// slot 1 stays. Materia is lost, no leak.
		tmp = src->createMateria("cure");
		bob->equip(tmp); // New equip at first free slot (0 in this case).
		std::cout << "Y " << *bob << std::endl;
		// No demo of equip max 4 slots, see Character.cpp:getSlotEquip().
		Ice * ice = new Ice();
		std::cout << "Z " << *ice << "\t"  << ice << std::endl;
		Ice icy = *ice; // ice is duplicated, new addres (heap and stack)
		std::cout << "AA " << icy << "\t"  << &icy << std::endl;
		Ice yce = icy; // Still, valid copy on new address.
		std::cout << "AB " << yce << "\t"  << &yce << std::endl;
		// me has ice at slot 0, let's use it three times (xp 30)
		me->use(0, *me);
		me->use(0, *me);
		me->use(0, *me);
		std::cout << "AC " << *me << std::endl;
		me->unequip(0);
		std::cout << "" << *me << std::endl;
		// me->equip(&icy); // Forbidden to equip stack material.
		me->equip(ice);
		// ice XP is back to 0 (it is another ice).
		std::cout << "AD " << *me << std::endl;
		std::cout << *ice << "\t"  << ice << std::endl; // same equipped address.
		std::cout << icy << "\t"  << &icy << std::endl;
		std::cout << yce << "\t"  << &yce << std::endl;
		me->use(0, *me);
		me->use(0, *me);
		me->use(0, *me);
		std::cout << "AE " << *me << std::endl;
		std::cout << *ice << "\t"  << ice << std::endl; // same equipped address.
		std::cout << icy << "\t"  << &icy << std::endl; // unchanged.
		std::cout << yce << "\t"  << &yce << std::endl; // unchanged.
		Ice ycy = Ice(yce); // Valid constructor, not usefull (stack material).
		std::cout << "AF " << ycy << "\t"  << &ycy << std::endl;
		// Ice ici = *ycy.clone(); // Valid constructor,
		// not usefull and yet leaks (stack).
		std::cout << "AGA " << *me << *bob << std::endl;
		me->unequip(0); // Ice unequipped from
		bob->unequip(1); // both.
		// me->equip(ice); // Invalid, ice has been deleted (it was on me).
		std::cout << "AGB " << *me << *bob << std::endl;
		ice = new Ice();
		me->equip(ice);
		bob->equip(ice); // Not valid to equip two Characters with the same
		// Materia, nothing happens. 
		me->use(0, *me);
		me->use(0, *me);
		me->use(0, *me);
		std::cout << "AGC " << *me << *bob << std::endl;
		// If a material.hpp does not have an use(), defaults to
		// -10 xp and no text. No demo, check AMateria.cpp:use().
		// Whenever a Materia is unequipped, it is freed (no re-equip):
		// a better hevior would be nice, suche as
		// AMateria * Character::unequip(int idx)
		// ...would return a pointer to a reusable Materia preserving the XP.
		// Then a well used materia could pass from one Character to anothea.r
		// This was not implemented to not mess with the function
		// given as void in ICharacter.hpp.
		// Bonus: operators << on all objects.
		delete me;
		delete bob;
		delete src;
		// No leaks!
	}
	return 0;
}
