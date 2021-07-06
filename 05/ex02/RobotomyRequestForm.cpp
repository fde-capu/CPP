/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:42:31 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/05 15:59:47 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <sstream>

const std::string RobotomyRequestForm::default_form_name = "RobotomyRequestForm";

void randomNoise(int x, std::string wave_type)
{
	int hz;
	int dr;
	std::stringstream ss;
	for (int i = 0; i < x; i++)
	{
		hz = rand() % 1000 + 200;
		dr = rand() % 200 + 100;
		ss << "(speaker-test -t " << wave_type << " -f " << hz << " > /dev/null)& pid=$!; sleep 0." << dr << "s; kill -9 $pid;";
	}
	std::cout << "[playing drilling noises]" << std::endl;
	ss << "sleep 0.8s;";
	system(ss.str().c_str());
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string u_target)
: Form(default_form_name, default_sign_grade, default_exec_grade)
{
	deb("RobotomyForm created.");
	setTarget(u_target);
	return ;
}

void RobotomyRequestForm::action() const
{
	deb("Executing Robotoby.");
	randomNoise(6, "pink");
	if (rand() % 2)
		std::cout << getTarget() << " has been successfully robotomized." << std::endl;
	else
		std::cout << getTarget() << " failed to be robotomized." << std::endl;
	return ;
}
