/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:56:53 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/05 12:29:43 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <string>
# include <iostream>
# include "Debs.hpp"
# include "Bureaucrat.hpp"
class Bureaucrat;

# define FORM_LOWEST_GRADE 150
# define FORM_HIGHEST_GRADE 1
# define IS_SIGNED_AT_BEGINNING 0

class GradeExceptions
{
	public:
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
		int checkRange(int, int, int);
};

class Form : public GradeExceptions
{
	private:
		const std::string name;
		bool is_signed;
		const int authority_to_sign;
		const int authority_to_execute;
	public:
		std::string getName() const;
		int isSigned() const;
		int getAuthorityToSign() const;
		int getAuthorityToExec() const;
		Form(std::string, int, int);
		Form(Form const & src);
		Form & operator = (Form const & rhs);
		~Form(void);
		Form * clone() const;
		void beSigned(const Bureaucrat &);
};

std::ostream & operator << (std::ostream & o, Form const & self);

#endif
