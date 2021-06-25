/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:58:31 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/29 10:13:12 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string u_target)
: Form("PresidentialPardonForm", 25, 5)
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

PresidentialPardonForm * PresidentialPardonForm::clone() const
{
	return new PresidentialPardonForm(getTarget());
}
