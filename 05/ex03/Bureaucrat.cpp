/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:02:49 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/06 21:30:03 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>
#include "Debs.hpp"

Bureaucrat::Bureaucrat(void)
: name("Ze Bedelho"), grade(150)
{
	deb("Bureaucrat::Default creation, default values.");
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
: name(src.getName()), grade(src.getGrade())
{
	deb("Bureaucrat::Constructor by reference.");
	*this = src;
	return ;
}

Bureaucrat & Bureaucrat::operator = (Bureaucrat const & rhs)
{
	deb("Bureaucrat::Assignation, `operator =`.");
	(void)rhs;
	return *this;
}

std::ostream & operator << (std::ostream & o, Bureaucrat const & self)
{
	o << self.getName() << ", bureaucrat grade " << self.getGrade() << "." <<  std::endl;
	return o;
}

Bureaucrat::~Bureaucrat(void)
{
	deb("::Bureaucrat~Destructor");
	return ;
}

std::string Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

void Bureaucrat::incrementGrade(int x)
{
	setGrade(grade - x); // Minus. Whatever.
	return ;
}

void Bureaucrat::decrementGrade(int x)
{
	setGrade(grade + x); // Plus. Whatever.
	return ;
}

int Bureaucrat::setGrade(int u_grade)
{
	try
	{
		if (u_grade > BUREAU_LOWEST_GRADE) // Yes, grades are upside down...
			throw GradeTooLowException();
		if (u_grade < BUREAU_HIGHEST_GRADE) // ...so the signs < > are correct.
			throw GradeTooHighException();
		grade = u_grade;
	}
	catch (GradeTooLowException & e)
	{
		grade = BUREAU_LOWEST_GRADE;
		std::cout << e.what() << std::endl;
	}
	catch (GradeTooHighException & e)
	{
		grade = BUREAU_HIGHEST_GRADE;
		std::cout << e.what() << std::endl;
	}
	return getGrade();
}

Bureaucrat::Bureaucrat(std::string u_name, int u_grade)
: name(u_name), grade(setGrade(u_grade))
{
	return ;
}

void Bureaucrat::signForm(Form & form)
{
	if (!static_cast<bool>(&form))
	{
		std::cout << "WTF you intern! Where is the form?" << std::endl;
		return ;
	}
	if (form.isSigned())
	{
		std::cout << name << " cannot sign " << form.getName() << " because it is already signed." << std::endl;
		return ;
	}
	form.beSigned(*this);
	if (form.isSigned())
		std::cout << name << " signs " << form.getName() << std::endl;
	else
		std::cout << name << " could not sign " << form.getName() << " because of not enough grade." << std::endl;
	return ;
}

void Bureaucrat::executeForm(Form const & form)
{
	if (!static_cast<bool>(&form))
	{
		std::cout << "Studip intern! Cannot execute unexistent form!" << std::endl;
		return ;
	}
	std::string exec_test = form.execute(*this);
	if (exec_test == "")
		std::cout << getName() << " executes " << form.getName() << "." << std::endl;
	else
		std::cout << exec_test << std::endl;
	return ;
}
