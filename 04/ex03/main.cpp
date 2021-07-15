/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:56:22 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/15 17:20:15 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "PlanctonHoney.hpp"
#include "HypnoGem.hpp"
#include "MuddyWaters.hpp"
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
		std::cout << "========== MateriaSource =========" << std::endl;

		MateriaSource * mat_src = new MateriaSource();
		std::cout << "[ A ] " << *mat_src << std::endl;

		mat_src->learnMateria(new Ice());
		mat_src->learnMateria(new Cure());
		std::cout << "[ B ] " << *mat_src << std::endl;
		
		mat_src->learnMateria(new Ice()); // Valid: learnMateria is not necessarily unique.
		std::cout << "[ C ] " << *mat_src << std::endl;
		
		mat_src->learnMateria(new Cure()); // Takes a maximum of four learnings,
		mat_src->learnMateria(new Ice()); // This does nothing, slots are full. new Ice() is freed.
		std::cout << "[ D ] " << *mat_src << std::endl;
		// The subject underlies same material learning has the only
		// practical effect of taking a learning slot.
		
		{
			MateriaSource src_cp = *mat_src; // Deep copy of MateriaSource (bonus).
			std::cout << "[ E ] " << src_cp << std::endl; // Check: new addresses.
		}
		
		{
			MateriaSource src_cp = MateriaSource(*mat_src); // Reference constructor (also deep), bonus.
			std::cout << "[ F ] " << src_cp << std::endl;
		}
		
		std::cout << "========== Character and AMateria =========" << std::endl;
		Character * me = new Character("Eu");
		std::cout << "[ A ] " << *me << std::endl;
		
		AMateria * materia;
		materia = mat_src->createMateria("ice");
		std::cout << "[ B ] " << *materia << "\t" << materia << std::endl;

		me->equip(materia);
		std::cout << "[ C ] " << *me << std::endl;
		
		me->equip(materia); // Does nothing when equipping any aready equipped materia.
		std::cout << "[ D ] Same: " << *me << std::endl;
		
		materia = mat_src->createMateria("foo"); // Materia gets rejected, not learned, nothing done.
		std::cout << "[ E ] Null pointer address: " << materia << std::endl;

		materia = mat_src->createMateria("cure");
		std::cout << "[ F ] " << *materia << "\t" << materia << std::endl;
		
		me->equip(materia);
		std::cout << "[ G ] " << *me << std::endl;
		AMateria * materia_save_1 = materia; // (*)

		std::cout << "========== Materia Use =========" << std::endl;

		Character * bob = new Character("Bob");
		std::cout << "[ A ] " << *bob << std::endl;
		
		me->use(1, *bob); // 1 is for "cure" ('me' second slot).
		std::cout << "[ B ] " << *me << std::endl; // XP has increased
		
		std::cout << "[ C ] " << *mat_src << std::endl; // source XP is always 0 (learned but not created materia).
		
		materia = mat_src->createMateria("cure");
		bob->equip(materia);
		bob->use(0, *me); // Uses once (+10 XP). Prints to srcreen.
		bob->use(1, *me); // Does nothing (unequipped).
		bob->use(-6, *me); // Does nothing (invalid parameter).
		bob->use(42, *me); // Does nothing (invalid parameter).
		bob->use(0, *bob); // Use again (+10 XP = 20). On selft also works. Prints to srcreen.
		std::cout << "[ D ] " << *bob << std::endl;
		AMateria * materia_save_2 = materia; // (*)
		
		std::cout << "========== Character Deep Copy =========" << std::endl;
		{
			std::cout << "<<< Deep Copy Test operator= >>>" << std::endl;
			Character bobby = *bob; // Deep copy of Character.
			std::cout << "[ A ] Bobby copied: " << bobby << std::endl;
			// bobby's equipment is a duplicate, check address.
			// XP of duplicate is set to 0 intentionally.

			bobby.use(0, *me);
			std::cout << "[ B ] Bobby after use(0): " << bobby << std::endl;
			std::cout << "[ C ] Bob remais the same: " << *bob << std::endl;
			// Materials XP runs only on the copy.
			std::cout << "<<< out of scope >>>" << std::endl << std::endl;
		}

		{
			std::cout << "<<< Deep Copy Test by reference >>>" << std::endl;
			Character bobby = Character(*bob); // By reference. Same tests as above.
			std::cout << "[ D ] Bobby copied: " << bobby << std::endl;
			bobby.use(0, *me);
			std::cout << "[ E ] Bobby after use: " << bobby << std::endl;
			std::cout << "[ F ] Bob is still the smae: " << *bob << std::endl;
			std::cout << "<<< out of scope >>>" << std::endl;
		}
		
		std::cout << "========== Unequip =========" << std::endl;
		materia = mat_src->createMateria("ice");
		bob->equip(materia);
		std::cout << "[ A ] " << *bob << std::endl;
		bob->unequip(0); // Materia at slot 0 is unattached. Slot [1] stays. materia_save_2. (*)
		std::cout << "[ B ] " << *bob << std::endl;
//		AMateria * materia_save_3 = materia; // Save. (*)
		materia = mat_src->createMateria("cure");
		bob->equip(materia); // New equip at first free slot (0 in this case).
		std::cout << "[ C ] " << *bob << std::endl;

		std::cout << "========== Custom Materials =========" << std::endl;
		// For the demo of max 4 slots per Character, we need material diversity:
		MateriaSource * custom_materials = new MateriaSource();
		custom_materials->learnMateria(new PlanctonHoney());
		custom_materials->learnMateria(new HypnoGem());
		custom_materials->learnMateria(new MuddyWaters());
		std::cout << "[ A ]" << std::endl << *custom_materials << std::endl;
		materia = custom_materials->createMateria("plancton honey");
		bob->equip(materia);
		materia = custom_materials->createMateria("gem of hypnosis");
		bob->equip(materia);
		materia = custom_materials->createMateria("muddy waters");
		bob->equip(materia); // Nothing done, slots are full.
		std::cout << "[ B ]" << std::endl << *bob << std::endl;
		bob->unequip(1);
		bob->equip(materia);
		std::cout << "[ C ]" << std::endl << *bob << std::endl;
		bob->use(1, *bob);
		bob->use(2, *me);
		bob->use(3, *me);
		std::cout << "[ D ]" << std::endl << *bob << std::endl;

		std::cout << "========== More Materials Test =========" << std::endl;
		std::cout << "[ A ] Remember: " << *me << std::endl;
		me->use(1, *me);
		me->use(1, *me);
		me->use(1, *me);
		std::cout << "[ B ] After 3 uses: " << *me << std::endl;
		me->unequip(1); // Old cure. materia_save_1 (*)
		std::cout << "[ C ] Cure unequipped: " << *me << std::endl;
		Cure * cure = new Cure();
		std::cout << "[ D ] New cure, new address: " << *cure << "\t"  << cure << std::endl;
		me->equip(cure);
		std::cout << "[ E ] Verify: " << *me << std::endl;
		// This equips cure directly, not "AMateria * MateriaSource::learnMateria(...)".
		// cure XP is back to 0 (it is another one). Address matches.
		
		std::cout << "[ F ] 'me' uses 42 times:" << std::endl;
		for (int i = 0; i < 42; i++) me->use(1, *bob);
		// Pointer `*cure` still holds the same 'me' has on slot [1], with 30 XP. So we can:
		std::cout << "[ G ] Check 'me' again: " << *me << std::endl;

		me->unequip(1);
		bob->unequip(0);
		bob->equip(cure);
		std::cout << "[ H ] Switched: " << *bob << std::endl;
		std::cout << "[ I ] " << *me << std::endl;
		
		std::cout << "========== Clone Test =========" << std::endl;
		// `virtual AMateria::AMateria * clone() const = 0;`
		// This function is used throughout the code.
		// Demo it works:
		Cure * cure_cp = cure->clone();
		std::cout << "[ A ] cure_cp: " << *cure_cp << "\t" << cure_cp << std::endl;
		// Again, XP is set to zero because it is what makes sense for a game.

		bob->unequip(0);
		bob->equip(cure_cp);
		std::cout << "[ B ] " << *bob << std::endl;
		bob->use(0, *me); // Clone is usable.
		std::cout << "[ C ] " << *bob << std::endl;

		//
		// Bonus: operators << on all objects. Usefull for demo!
		//
		// (*)
		// If materia is not manually freed, or if it is not equipped when Character
		// dies, it will leak.
		// Whenever a Materia is unequipped, it is NOT freed:
		// Subject: "The unequip method must NOT delete Materia!"
		// Better would be, instead of `void Character::unequip(int)`, as given,
		// use `AMateria * Character::unequip(int)`.
		// Then we could retrieve a reusable pointer preserving XP.
		// As `void`, when unnequipping, the address might be forgotten.
		// In short, all unequipped materia must be re-equipped (left
		// to the Character death to free it) or manually freed
		// (then the user must be extra attentive about it).
		//

		delete me;
		delete bob;
		delete mat_src;
		delete custom_materials;
		delete materia_save_1;
		delete materia_save_2;
//		delete materia_save_3;
		// No leaks!
	}
	return 0;
}
