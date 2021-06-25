/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:56:43 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/19 14:56:43 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	std::cout << "A" << std::endl;
	Bureaucrat ze; // Default creation, default values.
	std::cout << ze << &ze << std::endl;
	std::cout << "B" << std::endl;
	Bureaucrat mane(ze); // Reference constructor.
	std::cout << mane << &mane << std::endl;
	std::cout << "C" << std::endl;
	Bureaucrat pangua = mane; // Assignation.
	std::cout << pangua << &pangua << std::endl;
	std::cout << "D" << std::endl;
	Bureaucrat * fulano = new Bureaucrat; // Pointer default creation.
	std::cout << *fulano << fulano << std::endl;
	std::cout << "E" << std::endl; // All Bureaucrats are unique.
	ze.incrementGrade(5);
	std::cout << ze << mane << pangua << *fulano << std::endl;
	mane.incrementGrade(10);
	std::cout << ze << mane << pangua << *fulano << std::endl;
	pangua.incrementGrade(20);
	std::cout << ze << mane << pangua << *fulano << std::endl;
	fulano->incrementGrade(50);
	std::cout << ze << mane << pangua << *fulano << std::endl;
	std::cout << "F" << std::endl;
	Bureaucrat beltrano(ze); // Demo of copying grade values (reference).
	std::cout << beltrano << std::endl;
	Bureaucrat sicrano = mane; // (Assignation.)
	std::cout << sicrano << std::endl;
	std::cout << "G" << std::endl;
	Bureaucrat tom("Tom", 42); // Custom constructor.
	std::cout << tom << std::endl;
	std::cout << "H" << std::endl;
	Bureaucrat dick("Dick", -42); // Exception catcher (too HIGH).
	std::cout << dick << std::endl; // Defaults to HIGHEST_GRADE.
	std::cout << "I" << std::endl;
	Bureaucrat harry("Harry", 151); // Exception (too LOW).
	std::cout << harry << std::endl; // Defaults to LOWEST_GRADE.
	std::cout << "J" << std::endl;
	dick.decrementGrade(21);
	std::cout << dick << std::endl;
	dick.incrementGrade(42); // Exception, too high.
	std::cout << dick << std::endl; // Defaults to HIGHEST_GRADE.
	std::cout << "K" << std::endl;
	harry.incrementGrade(55);
	std::cout << harry << std::endl;
	harry.decrementGrade(555);
	std::cout << harry << std::endl; // Defaults to LOWEST_GRADE.
	std::cout << "L" << std::endl;
	harry.incrementGrade(77);
	std::cout << harry << std::endl;
	Bureaucrat full_copy(harry); // Name is also copied.
	std::cout << full_copy << std::endl;
	delete fulano;
	return 0;
}
