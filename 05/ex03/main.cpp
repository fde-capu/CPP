/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 10:18:25 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/29 10:29:45 by fde-capu         ###   ########.fr       */
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
	// First argument must ressemble a Form name:
	rrf = someRandomIntern.makeForm("some robot stuff", "Bender");
	// But if it does not match anything, like:
	delete rrf;
	std::cout << "B" << std::endl;
	rrf = someRandomIntern.makeForm("ZZZ", "Bender");
	// then the imcompetent Intern delivers NULL.
	// This solution was chosen over delivering a random or generic form.
	delete rrf; // This is fine but useless (rrf == 0);
	std::cout << "C" << std::endl;
	rrf = someRandomIntern.makeForm("Form", "Bender");
	// This will match all Forms, so it is also NULL.
	std::cout << "D" << std::endl;
	rrf = someRandomIntern.makeForm("presid.", "Bender");
	delete rrf;
	std::cout << "E" << std::endl;
	rrf = someRandomIntern.makeForm("srhuberuy", "Bender");
	// Resemblance also works.
	delete rrf;
	std::cout << "F" << std::endl;
	// Let us demonstrate the Forms can be signed and executed.
	Bureaucrat ze;
	std::cout << ze << std::endl;
	Form * yup;
	yup = someRandomIntern.makeForm("shurber", "home.txt");
	ze.signForm(*yup);
	ze.incrementGrade(5);
	std::cout << ze << std::endl;
	ze.signForm(*yup);
	std::cout << *yup << std::endl;
	ze.executeForm(*yup);
	ze.incrementGrade(8);
	std::cout << ze << std::endl;
	ze.executeForm(*yup);
	system("cat home.txt"); // Demo of output file (you should see a tree).
	delete yup;
	std::cout << "G" << std::endl;
	yup = someRandomIntern.makeForm("robtob", "Ex-human");
	ze.signForm(*yup);
	ze.incrementGrade(65);
	std::cout << ze << std::endl;
	ze.signForm(*yup);
	std::cout << *yup << std::endl;
	ze.executeForm(*yup);
	ze.incrementGrade(27);
	std::cout << ze << std::endl;
	ze.executeForm(*yup);
	delete yup;
	std::cout << "H" << std::endl;
	yup = someRandomIntern.makeForm("presdi", "Guil T. Per-son");
	ze.signForm(*yup);
	ze.incrementGrade(20);
	std::cout << ze << std::endl;
	ze.signForm(*yup);
	std::cout << *yup << std::endl;
	ze.executeForm(*yup);
	ze.incrementGrade(24);
	std::cout << ze << std::endl;
	ze.executeForm(*yup);
	delete yup;
	return 0;
}
