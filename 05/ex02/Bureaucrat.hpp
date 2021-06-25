/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:02:39 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/19 21:42:09 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <string>
# include <iostream>
# include <exception>
# include "Form.hpp"
class Form;

# define BUREAU_HIGHEST_GRADE 1
# define BUREAU_LOWEST_GRADE 150

/*
** Incrementing the grade must lower the grade. Whatever.
** It is like 1 is First Dan Bureaucrat and so on.
*/

class Bureaucrat
{
public:
	const std::string name;
	int grade;
	std::string getName() const;
	int getGrade() const;
	void incrementGrade(int);
	void decrementGrade(int);
	Bureaucrat(void);
	Bureaucrat(Bureaucrat const & src);
	Bureaucrat & operator = (Bureaucrat const & rhs);
	~Bureaucrat(void);
	Bureaucrat(std::string u_name, int u_grade);
	struct GradeTooHighException : public std::exception
	{
		const char * what() const throw()
		{
			return "Grade too HIGH!";
		}
	};
	struct GradeTooLowException : public std::exception
	{
		const char * what () const throw()
		{
			return "Grade too LOW!";
		}
	};
	int setGrade(int);
	void signForm(Form &);
	void executeForm(Form const & form);
};

std::ostream & operator << (std::ostream & o, Bureaucrat const & self);
void deb(std::string);

#endif
