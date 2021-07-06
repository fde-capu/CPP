/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:56:53 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/05 12:59:38 by fde-capu         ###   ########.fr       */
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
# define DEFAULT_INITIAL_GRADE LOWEST_GRADE

/*
** Incrementing the grade must lower the grade.
** Like Japanese ranking.
*/

class Bureaucrat
{
private:
	const std::string name;
	int grade;
public:
	std::string getName() const;
	int getGrade() const;
	void incrementGrade(int);
	void decrementGrade(int);
	Bureaucrat(void);
	Bureaucrat(Bureaucrat const & src);
	Bureaucrat & operator= (Bureaucrat const & rhs);
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
};

std::ostream & operator<< (std::ostream & o, Bureaucrat const & self);
void deb(std::string);

#endif
