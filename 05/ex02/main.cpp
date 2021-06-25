/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 10:18:25 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/19 22:24:48 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include "Form.hpp"
#include <sstream>
#include <cstdlib>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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
	std::cout << dick << std::endl; // Defaults to BUREAU_HIGHEST_GRADE.
	std::cout << "I" << std::endl;
	Bureaucrat harry("Harry", 151); // Exception (too LOW).
	std::cout << harry << std::endl; // Defaults to BUREAU_LOWEST_GRADE.
	std::cout << "J" << std::endl;
	dick.decrementGrade(21);
	std::cout << dick << std::endl;
	dick.incrementGrade(42); // Exception, too high.
	std::cout << dick << std::endl; // Defaults to BUREAU_HIGHEST_GRADE.
	std::cout << "K" << std::endl;
	harry.incrementGrade(55);
	std::cout << harry << std::endl;
	harry.decrementGrade(555);
	std::cout << harry << std::endl; // Defaults to BUREAU_LOWEST_GRADE.
	std::cout << "L" << std::endl;
	harry.incrementGrade(77);
	std::cout << harry << std::endl;
	Bureaucrat full_copy(harry); // Name is also copied.
	std::cout << full_copy << std::endl;
	delete fulano;
	std::cout << "-----------------------" << std::endl;
	std::cout << "A" << std::endl;
	Form form("First-Form", 150, 150); // Anyone can sign and execute.
	std::cout << form << std::endl;
	std::cout << "B" << std::endl;
	std::cout << ze << std::endl;
	ze.signForm(form);
	std::cout << form << std::endl;
	std::cout << "C" << std::endl;
	Form form2("Form Two", 145, 145); // ze has 145 grade.
	std::cout << form2 << std::endl;
	ze.signForm(form2);
	std::cout << form2 << std::endl;
	std::cout << "D" << std::endl;
	Form form3("Form Three", 140, 140); // ze has no grade to sign.
	std::cout << form3 << std::endl;
	ze.signForm(form3);
	std::cout << form3 << std::endl;
	std::cout << "E" << std::endl;
	ze.signForm(form); // This is already signed.
	beltrano.signForm(form);
	std::cout << "F" << std::endl;
	Form form_low("Form too low", 151, 151); // Too low, defaults to 150.
	std::cout << form_low << std::endl;
	std::cout << "G" << std::endl;
	Form form_high("Form too high", 0, 0); // Too high, defaults to 1.
	std::cout << form_high << std::endl;
	std::cout << "H" << std::endl;
	Form f_hi_no("Form high, normal", -8, 15);
	std::cout << f_hi_no << std::endl;
	std::cout << "I" << std::endl;
	Form f_lo_no("Form low, normal", 152, 42);
	std::cout << f_lo_no << std::endl;
	std::cout << "J" << std::endl;
	Form f_no_hi("Form normal, high", 37, -999);
	std::cout << f_no_hi << std::endl;
	std::cout << "K" << std::endl;
	Form f_no_lo("Form normal, low", 111, 9999);
	std::cout << f_no_lo << std::endl;
	std::cout << "L" << std::endl;
	Form f_hi_lo("Form high, low", -7, 777);
	std::cout << f_hi_lo << std::endl;
	std::cout << "M" << std::endl;
	Form f_lo_hi("Form low, high", 1000, -1000);
	std::cout << f_lo_hi << std::endl;
	std::cout << "N" << std::endl;
	Form f_copy = f_lo_hi; // Deep assignation.
	std::cout << f_copy << std::endl;
	std::cout << "O" << std::endl;
	ze.signForm(f_copy);
	std::cout << f_copy << f_lo_hi << std::endl; // f_lo_hi is not signed.
	std::cout << "P" << std::endl;
	Form f_cp2(f_lo_hi); // Deep reference.
	std::cout << f_cp2 << std::endl;
	ze.signForm(f_cp2);
	std::cout << f_cp2 << f_lo_hi << std::endl; // f_lo_hi is not signed.
	std::cout << "Q" << std::endl;
	Form * f_clone = f_lo_hi.clone(); // Clone method (bonus).
	std::cout << *f_clone << std::endl;
	ze.signForm(*f_clone);
	std::cout << *f_clone << f_lo_hi << std::endl;
	delete f_clone;
	// Moreso: there have been no request for implementing the
	// execute function. This will happen in the next exercise.
	std::cout << "-----------------------" << std::endl;
	std::string error_msg;
	std::cout << "Chapter IV Exercise 02: No, you need form 28B, not 28C..." << std::endl;
	srand (time(NULL)); // Needed random seed.
	std::cout << ze << std::endl;
	std::cout << "A" << std::endl;
	Form base("Simple Base Form (no action)", 150, 150);
	std::cout << base << std::endl;
	error_msg = base.execute(ze); // Not signed form.
	std::cout << error_msg << std::endl;
	ze.signForm(base); // Now signed.
	error_msg = base.execute(ze); // Executes, but there is no action associated.
	std::cout << error_msg << std::endl;
	ze.executeForm(base); // This syntax is the implementation needed in the subject. Auto prints error if any.
	std::cout << "B" << std::endl;
	ShrubberyCreationForm shrub("home.txt");
	std::cout << shrub << std::endl;
	ze.executeForm(shrub); // Not enough grade.
	ze.signForm(shrub); // There is enough grade to sign (145 == 145).
	ze.executeForm(shrub); // Not enough grade (again, but now the form is signed).
	std::cout << shrub << std::endl;
	ze.incrementGrade(8); // Now ze is 137.
	std::cout << ze << std::endl;
	ze.executeForm(shrub); // It is executed.
	system("cat home.txt"); // Demo of output file (you should see a tree).
	// system("rm -f home.txt"); // Leaving the file for demo purposes.
	std::cout << "C" << std::endl;
	ze.incrementGrade(300); // Now ze is grade 1.
	std::cout << ze << std::endl;
	RobotomyRequestForm robotomy("Cyborg");
	std::cout << robotomy << std::endl;
	ze.executeForm(robotomy); // Not signed.
	ze.signForm(robotomy);
	ze.executeForm(robotomy); // Now execs (noise sounds and 50% chance of success).
	std::cout << "D" << std::endl;
	PresidentialPardonForm pardon("Guilty person");
	std::cout << pardon << std::endl;
	ze.executeForm(pardon); // Not signed.
	ze.signForm(pardon);
	ze.executeForm(pardon);
	std::cout << "E" << std::endl;
	for (int i = 0; i < 10; i++)
		ze.executeForm(robotomy); // Check statistics 50% success (test more times for better accuracy).
	std::cout << std::endl;
	return 0;
}
