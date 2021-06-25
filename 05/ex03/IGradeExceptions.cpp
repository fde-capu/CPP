/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IGradeExceptions.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 15:28:17 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/19 15:28:36 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IGradeExceptions.hpp"
#include <iostream>

int IGradeExceptions::checkRange(int u_grade, int u_min, int u_max)
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
