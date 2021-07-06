/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:57:00 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/05 15:59:11 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "Form.hpp"
# include <string>

class PresidentialPardonForm : public Form
{
	private:
		virtual void action() const;
		static const std::string default_form_name;
		static const unsigned int default_sign_grade = 25;
		static const unsigned int default_exec_grade = 5;
	public:
		PresidentialPardonForm(std::string u_target);
};

#endif
