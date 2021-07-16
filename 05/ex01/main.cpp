/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:56:53 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/16 09:27:57 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include "Form.hpp"

int main()
{
	std::cout << "SAME AS BEFORE" << std::endl;
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

	std::cout << std::endl;
	std::cout << "/// END OF SAME AS BEFORE" << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << std::endl;

	std::cout << std::endl << "A // Anyone can sign and execute this form:" << std::endl;
	Form firstForm("First-Form", 150, 150);
	std::cout << firstForm << std::endl;

	std::cout << "B // For example, 'ze':" << std::endl;
	std::cout << ze << std::endl;
	ze.signForm(firstForm);
	std::cout << firstForm << std::endl;

	std::cout << std::endl << "C // ze can even sign if == the required grade." << std::endl;
	Form form2("Form Two", 145, 145);
	std::cout << form2 << std::endl;
	ze.signForm(form2);
	std::cout << form2 << std::endl;

	std::cout << std::endl << "D // But not this time:" << std::endl;
	Form form3("Form Three", 140, 140);
	std::cout << form3 << std::endl;
	ze.signForm(form3);
	std::cout << form3 << std::endl;
	std::cout << " // Form remains unsigned." << std::endl;

	std::cout << std::endl << "E // First-Form is already signed." << std::endl;
	ze.signForm(firstForm);
	beltrano.signForm(firstForm); // beltrano is identical to Bureaucrat(ze).

	std::cout << std::endl << "F // From constructor too low, defaults to lowest." << std::endl;
	Form form_low("Form too low", 151, 151);
	std::cout << form_low << std::endl;

	std::cout << std::endl << "G // Form constructor too high, defaults to highest." << std::endl;
	Form form_high("Form too high", 0, 0);
	std::cout << form_high << std::endl;

	std::cout << std::endl << "H // Other combinations of exceptions:" << std::endl;
	Form f_hi_no("Form high, normal", -8, 15);
	std::cout << f_hi_no << std::endl;
	std::cout << std::endl << "I" << std::endl;
	Form f_lo_no("Form low, normal", 152, 42);
	std::cout << f_lo_no << std::endl;
	std::cout << std::endl << "J" << std::endl;
	Form f_no_hi("Form normal, high", 37, -999);
	std::cout << f_no_hi << std::endl;
	std::cout << std::endl << "K" << std::endl;
	Form f_no_lo("Form normal, low", 111, 9999);
	std::cout << f_no_lo << std::endl;
	std::cout << std::endl << "L" << std::endl;
	Form f_hi_lo("Form high, low", -7, 777);
	std::cout << f_hi_lo << std::endl;
	std::cout << std::endl << "M // Keep this form in mind: _to_sign:150 (anyone), _to_exec:1 (only maximum authority)" << std::endl;
	Form f_lo_hi("Form low, high", 1000, -1000);
	std::cout << f_lo_hi << std::endl;

	std::cout << std::endl << "N // Deep assignation `operator=`." << std::endl;
	Form f_copy = f_lo_hi;
	std::cout << f_copy << std::endl;

	std::cout << std::endl << "O // The copy is not just another pointer:" << std::endl;
	ze.signForm(f_copy);
	std::cout << f_copy << f_lo_hi << std::endl; // f_lo_hi is not signed.

	std::cout << std::endl << "P // Deep reference, also different object." << std::endl;
	Form f_cp2(f_lo_hi);
	std::cout << f_cp2 << std::endl;
	ze.signForm(f_cp2);
	std::cout << f_cp2 << f_lo_hi << std::endl; // f_lo_hi is not signed.

	std::cout << std::endl << "Q // Clone method (bonus), also another object, on heap." << std::endl;
	Form * f_clone = f_lo_hi.clone();
	std::cout << *f_clone << std::endl;
	ze.signForm(*f_clone);
	std::cout << *f_clone << f_lo_hi << std::endl;

	// Moreso: there have been no request for implementing the
	// execute function. This will happen in the next exercise.

	delete f_clone;
	return 0;
}
