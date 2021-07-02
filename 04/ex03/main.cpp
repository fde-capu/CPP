/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:56:22 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/02 18:03:01 by fde-capu         ###   ########.fr       */
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
		MateriaSource * mat_src = new MateriaSource();
		std::cout << "A " << *mat_src << std::endl;

		mat_src->learnMateria(new Ice());
		mat_src->learnMateria(new Cure());
		std::cout << "B " << *mat_src << std::endl;
		
		mat_src->learnMateria(new Ice()); // Valid: learnMateria is not
		// necessarily unique.
		std::cout << "C " << *mat_src << std::endl;
		
		mat_src->learnMateria(new Cure()); // Takes a maximum of four learnings,
		std::cout << "D " << *mat_src << std::endl;
		// The subject underlies same material learning has the only
		// practical effect of taking a learning slot.
		
		mat_src->learnMateria(new Ice()); // This does nothing, slots are full.
		// In this case, (bonus) the "new Ice()" gets deleted (no leaks).
		std::cout << "E " << *mat_src << std::endl;
		
		{
			MateriaSource src_cp = *mat_src; // Deep copy of MateriaSource
			// (bonus).
			std::cout << "F " << src_cp << std::endl;
		}
		
		{
			MateriaSource src_cp = MateriaSource(*mat_src); // Reference
			// constructor (also deep), bonus.
			std::cout << "G " << src_cp << std::endl;
		}
		
		Character * me = new Character("TheCharacter(me)");
		std::cout << "H " << *me << std::endl;
		
		AMateria * materia; // Called "tmp" in subject's example.
		materia = mat_src->createMateria("foo"); // Materia gets rejected
		// (not learned, nothing done).
		
		materia = mat_src->createMateria("ice");
		AMateria * materia_save_1 = materia; // Save for later. Comments at the end. (*)
		std::cout << "I " << *materia << "\t" << materia << std::endl;
		
		me->equip(materia);
		std::cout << "J " << *me << std::endl;
		
		me->equip(materia); // Bonus. Does nothing when equipping the same.
		std::cout << "K " << *me << std::endl;
		
		materia = mat_src->createMateria("cure");
		std::cout << "L " << *materia << "\t" << materia << std::endl;
		
		me->equip(materia);
		std::cout << "M " << *me << std::endl;
		
		Character * bob = new Character("Bob");
		std::cout << "N " << *bob << std::endl;
		
		me->use(1, *bob); // 1 is for "cure" (second slot).
		std::cout << "O " << *me << std::endl; // XP has increased
		
		std::cout << "P " << *mat_src << std::endl; // source XP is always
		// 0 (learned but not created materia).
		
		materia = mat_src->createMateria("cure");
		AMateria * materia_save_2 = materia; // Save for later. Comments at the end. (*)
		bob->equip(materia); // New equip, mew naterial copy, own XP
		std::cout << "Q " << *bob << std::endl;
		
		bob->use(0, *me); // Uses once (+10 XP).
		bob->use(1, *me); // Does nothing (unequipped).
		bob->use(-6, *me); // Does nothing (invalid parameter).
		bob->use(42, *me); // Does nothing (invalid parameter).
		bob->use(0, *me); // Use again (+10 XP = 20).
		std::cout << "RA " << *bob << std::endl;
		std::cout << "RB " << *me << std::endl;
		
		{
			Character bobby = *bob; // Deep copy of Character.
			std::cout << "S " << bobby << std::endl;
			// Equipment is also duplicated, and their XP is
			// intentionally reset to zero.

			bobby.use(0, *me);
			std::cout << "TA " << bobby << std::endl;
			std::cout << "TB " << *bob << std::endl;
			// Materials XP runs only on the copy.
		}

		{
			Character bobby = Character(*bob); // By reference. Same
			// tests as above.
			std::cout << "U " << bobby << std::endl;
			bobby.use(0, *me);
			std::cout << "VA " << bobby << std::endl;
			std::cout << "VB " << *bob << std::endl;
		}
		
		std::cout << "WA " << *me << std::endl; // Just to remember "me" state.
		materia = mat_src->createMateria("ice");
		AMateria * materia_save_3 = materia; // Save for later. Comments at the end. (*)
		me->equip(materia); // It is another copy of "ice". It still cannot
		// be equiped (by design), because of the same name. Though is NOT freed.
		// If materia is not manually freed, or if it is not equipped when Character
		// dies, it will leak. Considerations at the end. (*)
		std::cout << "WB " << *me << std::endl; // "me" is still the same.

		bob->equip(materia); // Now that above materia is used.
		std::cout << "WC " << *bob << std::endl;
		
		bob->unequip(0);
		// slot 1 stays. Materia is unattached.
		// Good we have the address saved on materia_save_2, so we can free it later. (*)
		std::cout << "X " << *bob << std::endl; // Slot 0 is freed,
		
		materia = mat_src->createMateria("cure");
		bob->equip(materia); // New equip at first free slot (0 in this case).
		std::cout << "Y " << *bob << std::endl;
		// No demo of equip max 4 slots, (only working with two materias).
		// See Character.cpp:getSlotEquip() to check this behavior.
		
		Ice * ice = new Ice(); // ice on heap.
		std::cout << "Z " << *ice << "\t"  << ice << std::endl;
		
		Ice icy = *ice; // ice is duplicated, new addres (on stack).
		std::cout << "AA " << icy << "\t"  << &icy << std::endl;
		
		Ice yce = icy; // Still, valid copy (of copy) on new address.
		std::cout << "AB " << yce << "\t"  << &yce << std::endl;
		// me->equip(&icy); // Forbidden to equip stack materia.

		// "me" has ice on slot 0, let's use it three times (xp 30)
		me->use(0, *me);
		me->use(0, *me);
		me->use(0, *me);
		std::cout << "AC " << *me << std::endl;
		
		me->unequip(0);
		// Good we have the address saved on materia_save_1, so we can free it later. (*)
		std::cout << "AC2" << *me << std::endl;
		
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
		
		std::cout << *ice << "\t"  << ice << std::endl; // "me" slot 0 address to this.
		std::cout << icy << "\t"  << &icy << std::endl; // unchanged.
		std::cout << yce << "\t"  << &yce << std::endl; // unchanged.
		Ice ycy = Ice(yce); // Valid constructor, not usefull (stack material).
		std::cout << "AF " << ycy << "\t"  << &ycy << std::endl << std::endl;
		// Ice ici = *ycy.clone(); // Valid constructor,
		// not usefull and yet leaks: clone() makes a heap allocation,
		// then operator= copy its attributes, but the allocation is never used.

		std::cout << "AGA " << *me << *bob << std::endl; // Just remembering.
		me->unequip(0); // Ice unequipped. Saved on materia_save_3.
		bob->unequip(1); // Ice unequipped. Saved on materia_save_4.
		std::cout << "AGB " << *me << *bob << std::endl;
		bob->equip(ice); // Valid, since ice is still allocated (on "Z").
		// Note that the materia XP is also transfered (same object).
		std::cout << "AGC " << *me << *bob << std::endl;
		
		ice = new Ice();
		me->equip(ice);
		bob->equip(ice); // Not valid to equip two Characters with the same
		// Materia, nothing happens. 
		me->use(0, *me);
		me->use(0, *me);
		me->use(0, *me);
		std::cout << "AGC " << *me << *bob << std::endl;

		//
		// If a material class (children of AMateria.hpp) does not have an
		// virtual use(), defaults to +10 xp and shows no text.
		// Check AMateria.cpp:use().
		//
		// Bonus: operators << on all objects.
		//
		// (*)
		// Whenever a Materia is unequipped, it is NOT freed:
		// "The unequip method must NOT delete Materia!"
		// a better hevior would be:
		// AMateria * Character::unequip(int idx)
		// ...could return a pointer to a reusable Materia preserving the XP.
		// However, unequip() is prototyped as void in given ICharacter.hpp.
		// So - when unnequipping, the address might be forgotten.
		// That is why I have used those "materia_save_X" for this demo.
		// In short, all unequipped materia must be re-equipped
		// or manually freed.
		//

		delete me;
		delete bob;
		delete mat_src;
		delete materia_save_1;
		delete materia_save_2;
		delete materia_save_3;
		// No leaks!
	}
	return 0;
}
