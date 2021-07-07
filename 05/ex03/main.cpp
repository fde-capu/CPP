/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 10:18:25 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/06 12:29:29 by fde-capu         ###   ########.fr       */
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
#include "Intern.hpp"
#include "RatcliffObershelpSimilarity.hpp"

int main()
{
	srand(static_cast<unsigned int>(time(NULL)));
	Intern someRandomIntern;
	std::cout << "A" << std::endl;
	Form * rrf;
	// First argument must ressemble a Form name (poorly_writen_request, target):
	rrf = someRandomIntern.makeForm("some robot stuff", "Bender");
	delete rrf;
	std::cout << "B" << std::endl;
	// But if it does not match anything, like:
	rrf = someRandomIntern.makeForm("ZZZ", "Bender");
	// then the incompetent Intern delivers NULL. A pointer to NULL! Do NEVER sign a pointer to NULL.
	// This solution was chosen over delivering a random or generic form.
	delete rrf; // This is fine but useless (rrf == 0).
	std::cout << "C" << std::endl;
	rrf = someRandomIntern.makeForm("Form", "Bender");
	// This will match all Forms, so it is also undecidable.
	std::cout << "D" << std::endl;
	rrf = someRandomIntern.makeForm("presid.", "Bender");
	delete rrf;
	std::cout << "E" << std::endl;
	rrf = someRandomIntern.makeForm("srhuberuy", "Bender"); // Resemblance also works.
	delete rrf;
	std::cout << "F" << std::endl;
	// Let us demonstrate the Forms can be signed and executed.
	Bureaucrat ze;
	std::cout << ze << std::endl;
	Form * yup;
	yup = someRandomIntern.makeForm("shurber", "home.txt");
	ze.signForm(*yup); // 150 is too low. Needed 145.
	ze.incrementGrade(5);
	std::cout << ze << std::endl;
	ze.signForm(*yup); // Signed.
	std::cout << *yup << std::endl;
	ze.executeForm(*yup); // Can't execute, low grade.
	ze.incrementGrade(8); // 137.
	std::cout << ze << std::endl;
	ze.executeForm(*yup); // Form is executed.
	system("cat home.txt"); // Demo of output file (you should see a tree).
	delete yup;
	std::cout << "G" << std::endl;
	yup = someRandomIntern.makeForm("robtob f. dont mess up this time!!", "Ex-human");
	ze.signForm(*yup); // 137 can't sign.
	ze.incrementGrade(65); // 72.
	std::cout << ze << std::endl;
	ze.signForm(*yup); // Signs.
	std::cout << *yup << std::endl;
	ze.executeForm(*yup); // Needed 45.
	ze.incrementGrade(27); // 45.
	std::cout << ze << std::endl;
	ze.executeForm(*yup); // Done.
	delete yup;
	std::cout << "H" << std::endl;
	yup = someRandomIntern.makeForm("adress this to the president", "Guil T. Per-son");
	ze.signForm(*yup);
	ze.incrementGrade(20);
	std::cout << ze << std::endl;
	ze.signForm(*yup);
	std::cout << *yup << std::endl;
	ze.executeForm(*yup);
	ze.incrementGrade(24);
	std::cout << ze << std::endl;
	ze.executeForm(*yup); // Mr. Beeblebrox always forgives.
	delete yup;
	return 0;
}
