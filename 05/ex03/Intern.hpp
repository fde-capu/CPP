/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:14:36 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/29 09:16:03 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include <string>
# include <iostream>
# include "Form.hpp"

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# define ALL_I_KNOW \
	new ShrubberyCreationForm(""), \
	new RobotomyRequestForm(""), \
	new PresidentialPardonForm("")
# define THIS_MANY_FORMS 3
# define TEXT_SIMILARITY_READING 0.15

class Intern
{
	private:
		static const Form * all_I_need_to_know[THIS_MANY_FORMS];
		Form * toDo;
		Form * thinkHard(std::string);
	public:
		Intern(void);
		Intern(Intern const & src);
		Intern & operator = (Intern const & rhs);
		~Intern(void);
		Intern * clone() const;
		Form * makeForm(std::string, std::string);
};

std::ostream & operator << (std::ostream & o, Intern const & self);

#endif
