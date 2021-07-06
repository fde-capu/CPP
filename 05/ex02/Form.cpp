/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 10:20:23 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/06 08:17:23 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

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

std::string Form::getTarget() const
{
	return target;
}

void Form::setTarget(std::string u_target)
{
	target = u_target;
}

std::string Form::execute(Bureaucrat const & executor) const
{
	if (getAuthorityToExec() < executor.getGrade())
		return ("No execution: grade not enough.");
	if (!isSigned())
		return ("No execution: form is not signed.");
	action();
	return "";
}
