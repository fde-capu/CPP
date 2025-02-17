/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:56:53 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/05 12:58:12 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>
#include "Debs.hpp"

Bureaucrat::Bureaucrat(void)
: name("Ze Bedelho"), grade(DEFAULT_INITIAL_GRADE)
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

Bureaucrat & Bureaucrat::operator= (Bureaucrat const & rhs)
{
	deb("Bureaucrat::Assignation, `operator =`.");
	(void)rhs;
	return *this;
}

std::ostream & operator<< (std::ostream & o, Bureaucrat const & self)
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
	setGrade(grade - x); // Minus.
	return ;
}

void Bureaucrat::decrementGrade(int x)
{
	setGrade(grade + x); // Plus.
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
	catch (GradeTooLowException & e) // GrateToo* are std::exception subclasses.
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
	deb("Bureaucrat::signForm()");
	if (form.isSigned())
	{
		std::cout << name << " cannot sign " << form.getName() << " because it is already signed." << std::endl;
		return ;
	}
	form.beSigned(*this);
	if (form.isSigned())
		std::cout << name << " signs " << form.getName() << "." << std::endl;
	else
		std::cout << name << " could not sign " << form.getName() << " because of not enough grade." << std::endl;
	return ;
}
