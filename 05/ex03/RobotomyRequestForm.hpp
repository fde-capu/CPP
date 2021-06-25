/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:41:24 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/29 10:12:06 by fde-capu         ###   ########.fr       */
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
	public:
		RobotomyRequestForm(std::string u_target);
		virtual RobotomyRequestForm * clone() const;
};

#endif
