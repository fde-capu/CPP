/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:41:24 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/05 15:59:15 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "Form.hpp"
# include <string>

class RobotomyRequestForm : public Form
{
	private:
		virtual void action() const;
		static const std::string default_form_name;
		static const unsigned int default_sign_grade = 72;
		static const unsigned int default_exec_grade = 45;
	public:
		RobotomyRequestForm(std::string u_target);
};

#endif
