/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 10:18:12 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/29 10:03:36 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <string>
# include <iostream>
# include "Debs.hpp"
# include "Bureaucrat.hpp"
# include "IGradeExceptions.hpp"

class Bureaucrat;

# define FORM_LOWEST_GRADE 150
# define FORM_HIGHEST_GRADE 1

class Form : public IGradeExceptions
{
	private:
		const std::string name;
		int is_signed;
		const int authority_to_sign;
		const int authority_to_execute;
		std::string target;
		virtual void action() const;
	public:
		std::string getName() const;
		int isSigned() const;
		int getAuthorityToSign() const;
		int getAuthorityToExec() const;
		Form(std::string, int, int);
		Form(Form const & src);
		Form & operator = (Form const & rhs);
		virtual ~Form(void);
		virtual Form * clone() const;
		void beSigned(Bureaucrat &);
		std::string getTarget() const;
		void setTarget(std::string u_target);
		std::string execute(Bureaucrat const & executor) const;
};

std::ostream & operator << (std::ostream & o, Form const & self);

#endif
