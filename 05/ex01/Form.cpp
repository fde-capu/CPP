/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:56:53 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/19 14:56:53 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

int GradeExceptions::checkRange(int u_grade, int u_min, int u_max)
{
	int grade;
	try
	{
		if (u_grade > u_min) // Yes, grades are upside down...
			throw GradeTooLowException();
		if (u_grade < u_max) // ...so the signs < > are correct.
			throw GradeTooHighException();
		grade = u_grade;
	}
	catch (GradeTooLowException & e)
	{
		grade = u_min;
		std::cout << e.what() << std::endl;
	}
	catch (GradeTooHighException & e)
	{
		grade = u_max;
		std::cout << e.what() << std::endl;
	}
	return grade;
}

Form::Form(const std::string u_name, const int u_auth_to_sign, const int u_auth_to_exec)
: name(u_name), is_signed(0),
  authority_to_sign(checkRange(u_auth_to_sign, FORM_LOWEST_GRADE, FORM_HIGHEST_GRADE)),
  authority_to_execute(checkRange(u_auth_to_exec, FORM_LOWEST_GRADE, FORM_HIGHEST_GRADE))
{
	deb("Form::userConstructor.");
	return ;
}

Form::Form(Form const & src)
: name(src.getName()), is_signed(src.isSigned()),
  authority_to_sign(src.getAuthorityToSign()),
  authority_to_execute(src.getAuthorityToExec())
{
	deb("Form::Constructor by reference.");
	*this = src;
	return ;
}

Form & Form::operator = (Form const & rhs)
{
	deb("Form::Assignation, `operator =`.");
	(void)rhs;
	return *this;
}

std::ostream & operator << (std::ostream & o, Form const & self)
{
	o << "::Form::        Name: " << self.getName() << std::endl;
	o << "   Authority to Sign: " << self.getAuthorityToSign() << std::endl;
	o << "Authority to Execute: " << self.getAuthorityToExec() << std::endl;
	o << "              Signed: " << self.isSigned() << std::endl;
	return o;
}

Form::~Form(void)
{
	deb("Form::Destructor");
	return ;
}

Form * Form::clone() const
{
	return new Form(*this);
}

std::string Form::getName() const
{
	return name;
}

int Form::isSigned() const
{
	return is_signed;
}

int Form::getAuthorityToSign() const
{
	return authority_to_sign;
}

int Form::getAuthorityToExec() const
{
	return authority_to_execute;
}

void Form::beSigned(Bureaucrat & bu)
{
	deb("Form::beSigned()");
	int test_grade = checkRange(bu.getGrade(), authority_to_sign, FORM_HIGHEST_GRADE);
	is_signed = test_grade == bu.getGrade() ? 1 : 0;
	return ;
}
