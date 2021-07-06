/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:58:31 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/05 15:59:35 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

const std::string PresidentialPardonForm::default_form_name = "PresidentialPardonForm";

PresidentialPardonForm::PresidentialPardonForm(std::string u_target)
: Form(default_form_name, default_sign_grade, default_exec_grade)
{
	setTarget(u_target);
	deb("PresidentialPardonForm created.");
	return ;
}

void PresidentialPardonForm::action() const
{
	deb("Executing Pardon.");
	std::cout << getTarget() << " has been pardoned by Zafod Beeblebrox." << std::endl;
	return ;
}
