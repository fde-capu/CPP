/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:56:43 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/19 14:56:43 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>

void deb(std::string x)
{
	if (!DEBUG)
		return ;
	std::cout << x << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(void)
: name("Ze Bedelho"), grade(150)
{
	deb("::Default creation, default values.");
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
: name(src.getName()), grade(src.getGrade())
{
	deb("::Constructor by reference.");
	*this = src;
	return ;
}

Bureaucrat & Bureaucrat::operator = (Bureaucrat const & rhs)
{
	deb("::Assignation, `operator =`.");
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
	deb("::Destructor");
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
		if (u_grade > LOWEST_GRADE) // Yes, grades are upside down...
			throw GradeTooLowException();
		if (u_grade < HIGHEST_GRADE) // ...so the signs < > are correct.
			throw GradeTooHighException();
		grade = u_grade;
	}
	catch (GradeTooLowException & e)
	{
		grade = LOWEST_GRADE;
		std::cout << e.what() << std::endl;
	}
	catch (GradeTooHighException & e)
	{
		grade = HIGHEST_GRADE;
		std::cout << e.what() << std::endl;
	}
	return getGrade();
}

Bureaucrat::Bureaucrat(std::string u_name, int u_grade)
: name(u_name), grade(setGrade(u_grade))
{
	return ;
}
