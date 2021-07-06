/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:49:59 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/05 15:59:20 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "Form.hpp"
# include <string>

class ShrubberyCreationForm : public Form
{
	private:
		virtual void action() const;
		static const std::string default_form_name;
		static const unsigned int default_sign_grade = 145;
		static const unsigned int default_exec_grade = 137;
	public:
		ShrubberyCreationForm(std::string u_target);
};

#endif
