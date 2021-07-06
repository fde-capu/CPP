/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:56:43 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/05 12:39:03 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	std::cout << std::endl << "A // Default creation, default values, stack." << std::endl;
	Bureaucrat ze;
	std::cout << ze << &ze << std::endl;

	std::cout << std::endl << "B // Reference constructor, stack." << std::endl;
	Bureaucrat mane(ze);
	std::cout << mane << &mane << std::endl;
	
	std::cout << std::endl << "C // Assignation, stack." << std::endl;
	Bureaucrat pangua = mane;
	std::cout << pangua << &pangua << std::endl;
	
	std::cout << std::endl << "D // Pointer default creation, heap." << std::endl;
	Bureaucrat * fulano = new Bureaucrat;
	std::cout << *fulano << fulano << std::endl;
	
	std::cout << std::endl << "E // All Bureaucrats are unique." << std::endl;
	ze.incrementGrade(5);
	std::cout << ze << mane << pangua << *fulano << std::endl;
	mane.incrementGrade(11);
	std::cout << ze << mane << pangua << *fulano << std::endl;
	pangua.incrementGrade(21);
	std::cout << ze << mane << pangua << *fulano << std::endl;
	fulano->incrementGrade(42);
	std::cout << ze << mane << pangua << *fulano << std::endl;
	
	std::cout << std::endl << "F // Ref. constructor copies name and grade." << std::endl;
	Bureaucrat beltrano(ze);
	std::cout << beltrano << ze << std::endl;
	
	std::cout << std::endl << "G // Custom constructor." << std::endl;
	Bureaucrat tom("Tom", 42);
	std::cout << tom << std::endl;
	
	std::cout << std::endl << "H // Exception catcher (too HIGH)." << std::endl;
	Bureaucrat dick("Dick", -42); // Less is more.
	std::cout << dick << std::endl; // Defaults to HIGHEST_GRADE.

	std::cout << std::endl << "I // Exception (too LOW)." << std::endl;
	Bureaucrat harry("Harry", 151); // More is less.
	std::cout << harry << std::endl; // Defaults to LOWEST_GRADE.
	
	std::cout << std::endl << "J // incrementGrade() HIGH grade exception." << std::endl;
	dick.decrementGrade(21);
	std::cout << dick << std::endl;
	dick.incrementGrade(42); // Exception, too high.
	std::cout << dick << std::endl; // Defaults to HIGHEST_GRADE.
	
	std::cout << std::endl << "K // decrementGrade() LOW exception." << std::endl;
	harry.incrementGrade(55);
	std::cout << harry << std::endl;
	harry.decrementGrade(555); // Too low.
	std::cout << harry << std::endl; // Defaults to LOWEST_GRADE.
	
	std::cout << std::endl << "L // setGrade() working." << std::endl;
	harry.setGrade(1);
	std::cout << harry << std::endl;

	std::cout << std::endl << "M // setGrade() exception HIGH." << std::endl;
	harry.setGrade(0);
	std::cout << harry << std::endl;

	std::cout << std::endl << "N // setGrade() exception LOW." << std::endl;
	harry.setGrade(151);
	std::cout << harry << std::endl;

	std::cout << std::endl << "O // Getters." << std::endl;
	std::cout << "{{ " << harry.getName() << " : " << harry.getGrade() << " }}" << std::endl;

	delete fulano;
	return 0;
}
